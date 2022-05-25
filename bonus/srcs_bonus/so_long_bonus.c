/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:41:39 by adlecler          #+#    #+#             */
/*   Updated: 2022/05/25 14:30:53 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	ft_check_ber(char *str) // check si map est un fichier .ber
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (0);
	return (-1);
}

// si on peut ouvrir le fichier .ber (s'il existe)
int	ft_check_file(char *file)
{
	int	fd;

	fd = open(file, 0);
	if (fd < 0)
		return (-1);
	return (0);
}

void	ft_init_struct(t_game *game)
{
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->count_c = 0;
	game->count_mov = 0;
	game->x = 0;
	game->y = 0;
}

void	free_tab2d(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free_tab2d(game->map);
		exit (1);
	}
	game->img = mlx_new_image(game->mlx, game->x_max * 32, game->y_max * 32);
	game->mlx_win = mlx_new_window(game->mlx, (game->x_max + 1) * 32,
		(game->y_max + 1) * 32, "SO_LONG"); // block de 32 par 32
	if (load_texture(game) == -1)
	{
		free_tab2d(game->map);
		exit(1);
	}
	mlx_hook(game->mlx_win, 2, 1L << 0, events_key_manager, game);
	mlx_hook(game->mlx_win, 17, 1L << 2, echap_game_mouse, game);
	//Event pour gerer echap et croix
	mlx_loop_hook(game->mlx, ft_drawing, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_check_ber(av[1]) == -1 || ft_check_file(av[1]) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_init_struct(&game);
	if (ft_parsing(&game, av[1]) == -1)
		return (-1);
	if (ft_check_map_size(&game, av[1]) == -1)
		return (-1);
	if (ft_map_is_closed(&game, av[1]) == -1)
		return (-1);
	if (ft_map_is_closed2(&game, av[1]) == -1)
		return (-1);
	if (ft_check_char_map(&game, av[1]) == -1)
		return (-1);
	

	if (start_game(&game) == -1)
		return (-1);
	return (0);
}
