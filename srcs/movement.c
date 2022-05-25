/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:56:45 by adlecler          #+#    #+#             */
/*   Updated: 2022/05/25 13:46:20 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	first_mov(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
	game->texts_img[3], game->player[1] * 32, game->player[0] * 32);
}

void	ft_up(t_game *game)
{
	if (game->map[game->player[0] - 1][game->player[1]] == '1')
		return ;
	else if (game->map[game->player[0] - 1][game->player[1]] == 'C')
	{
		game->count_c++;
		game->count_mov++;
		game->map[game->player[0] - 1][game->player[1]] = '0';
		game->player[0]--;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0] - 1][game->player[1]] == '0')
	{	
		game->player[0]--;
		game->count_mov++;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0] - 1][game->player[1]] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->count_mov++;
			game->player[0]--;
			printf("Nombre de coups: %d\n", game->count_mov);
			printf("U WIN\n");
			free_tab2d(game->map);
			mlx_destroy_image(game->mlx, game->img);
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit (1);
		}
	}
}

void	ft_down(t_game *game)
{
	if (game->map[game->player[0] + 1][game->player[1]] == '1')
		return ;
	else if (game->map[game->player[0] + 1][game->player[1]] == 'C')
	{
		game->count_c++;
		game->count_mov++;
		game->map[game->player[0] + 1][game->player[1]] = '0';
		game->player[0]++;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0] + 1][game->player[1]] == '0')
	{	
		game->player[0]++;
		game->count_mov++;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0] + 1][game->player[1]] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->count_mov++;
			game->player[0]++;
			printf("Nombre de coups: %d\n", game->count_mov);
			printf("U WIN\n");
			free_tab2d(game->map);
			mlx_destroy_image(game->mlx, game->img);
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit (1);
		}
	}
}

void	ft_left(t_game *game)
{
	if (game->map[game->player[0]][game->player[1] - 1] == '1')
		return ;
	else if (game->map[game->player[0]][game->player[1] - 1] == 'C')
	{
		game->count_c++;
		game->count_mov++;
		game->map[game->player[0]][game->player[1] - 1] = '0';
		game->player[1]--;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] - 1] == '0')
	{
		game->player[1]--;
		game->count_mov++;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] - 1] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->player[1]--;
			game->count_mov++;
			printf("Nombre de coups: %d\n", game->count_mov);
			printf("U WIN\n");
			free_tab2d(game->map);
			mlx_destroy_image(game->mlx, game->img);
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit (1);
		}
	}
}

void	ft_right(t_game *game)
{
	if (game->map[game->player[0]][game->player[1] + 1] == '1')
		return ;
	else if (game->map[game->player[0]][game->player[1] + 1] == 'C')
	{
		game->count_c++;
		game->count_mov++;
		game->map[game->player[0]][game->player[1] + 1] = '0';
		game->player[1]++;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] + 1] == '0')
	{
		game->player[1]++;
		game->count_mov++;
		printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] + 1] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->count_mov++;
			game->player[1]++;
			printf("Nombre de coups: %d\n", game->count_mov);
			printf("U WIN\n");
			free_tab2d(game->map);
			mlx_destroy_image(game->mlx, game->img);
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit (1);
		}
	}
}
