/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:56:45 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/06 17:56:38 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	first_mov(t_game *game)
{
	game->map[game->player[0]][game->player[1]] = '0';
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
		game->map[game->player[0] - 1][game->player[1]] = '0';
		game->player[0]--;
		ft_printf("Nombre de coups: %d\n", ++game->count_mov);
	}
	else if (game->map[game->player[0] - 1][game->player[1]] == '0')
	{	
		game->player[0]--;
		game->count_mov++;
		ft_printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0] - 1][game->player[1]] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->count_mov++;
			game->player[0]--;
			ft_printf("Nombre de coups: %d\n", game->count_mov);
			exit_win(game);
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
		game->map[game->player[0] + 1][game->player[1]] = '0';
		game->player[0]++;
		ft_printf("Nombre de coups: %d\n", ++game->count_mov);
	}
	else if (game->map[game->player[0] + 1][game->player[1]] == '0')
	{	
		game->player[0]++;
		game->count_mov++;
		ft_printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0] + 1][game->player[1]] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->count_mov++;
			game->player[0]++;
			ft_printf("Nombre de coups: %d\n", game->count_mov);
			exit_win(game);
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
		game->map[game->player[0]][game->player[1] - 1] = '0';
		game->player[1]--;
		ft_printf("Nombre de coups: %d\n", ++game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] - 1] == '0')
	{
		game->player[1]--;
		game->count_mov++;
		ft_printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] - 1] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->player[1]--;
			game->count_mov++;
			ft_printf("Nombre de coups: %d\n", game->count_mov);
			exit_win(game);
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
		game->map[game->player[0]][game->player[1] + 1] = '0';
		game->player[1]++;
		ft_printf("Nombre de coups: %d\n", ++game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] + 1] == '0')
	{
		game->player[1]++;
		game->count_mov++;
		ft_printf("Nombre de coups: %d\n", game->count_mov);
	}
	else if (game->map[game->player[0]][game->player[1] + 1] == 'E')
	{
		if (game->c == game->count_c)
		{
			game->count_mov++;
			game->player[1]++;
			ft_printf("Nombre de coups: %d\n", game->count_mov);
			exit_win(game);
		}
	}
}
