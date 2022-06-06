/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:41:39 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/06 15:00:20 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

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
			(game->y_max + 1) * 32, "SO_LONG");
	if (load_texture(game) == -1 || load_textures_numbers(game) == -1)
		exit(1);
	mlx_hook(game->mlx_win, 2, 1L << 0, events_key_manager, game);
	mlx_hook(game->mlx_win, 17, 1L << 2, echap_game_mouse, game);
	mlx_loop_hook(game->mlx, ft_drawing, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.count = 0;
	if (ac != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 32);
		return (1);
	}
	if (ft_check_ber(av[1]) == -1 || ft_check_file(av[1]) == -1)
	{
		write(2, "Error\nWrong map extension or non-existent file\n", 48);
		return (1);
	}
	ft_init_struct(&game);
	if (ft_parsing(&game, av[1]) == -1)
		return (1);
	if (ft_check_map_size(&game) == -1)
		return (1);
	if (ft_map_is_closed(&game) == -1 || ft_map_is_closed2(&game) == -1)
		return (1);
	if (ft_check_char_map(&game) == -1)
		return (1);
	if (start_game(&game) == -1)
		return (1);
	return (0);
}
