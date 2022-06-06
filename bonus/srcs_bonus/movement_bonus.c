/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:56:45 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/06 13:28:48 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	first_mov(t_game *game)
{
	game->map[game->player[0]][game->player[1]] = '0';
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->texts_img[4], game->player[1] * 32, game->player[0] * 32);
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
	}
	else if (game->player[0] - 1 == game->dofi[0]
		&& game->player[1] == game->dofi[1])
	{
		game->player[0]--;
		printf("U were caught by Dofi\n");
		exit_lose(game);
	}
	else if (game->map[game->player[0] - 1][game->player[1]] == '0')
	{	
		game->player[0]--;
		game->count_mov++;
	}
	else if (game->map[game->player[0] - 1][game->player[1]] == 'E')
		exit_up(game);
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
	}
	else if (game->player[0] + 1 == game->dofi[0]
		&& game->player[1] == game->dofi[1])
	{
		game->player[0]++;
		printf("U were caught by Dofi\n");
		exit_lose(game);
	}
	else if (game->map[game->player[0] + 1][game->player[1]] == '0')
	{	
		game->player[0]++;
		game->count_mov++;
	}
	else if (game->map[game->player[0] + 1][game->player[1]] == 'E')
		exit_down(game);
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
	}
	else if (game->player[0] == game->dofi[0]
		&& game->player[1] - 1 == game->dofi[1])
	{
		game->player[1]--;
		printf("U were caught by Dofi\n");
		exit_lose(game);
	}
	else if (game->map[game->player[0]][game->player[1] - 1] == '0')
	{
		game->player[1]--;
		game->count_mov++;
	}
	else if (game->map[game->player[0]][game->player[1] - 1] == 'E')
		exit_left(game);
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
	}
	else if (game->player[0] == game->dofi[0]
		&& game->player[1] + 1 == game->dofi[1])
	{
		game->player[1]++;
		printf("U were caught by Dofi\n");
		exit_lose(game);
	}
	else if (game->map[game->player[0]][game->player[1] + 1] == '0')
	{
		game->player[1]++;
		game->count_mov++;
	}
	else if (game->map[game->player[0]][game->player[1] + 1] == 'E')
		exit_right(game);
}
