/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:23:22 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/24 10:46:36 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	exit_up(t_game *game)
{
	if (game->c == game->count_c)
	{
		game->count_mov++;
		game->player[0]--;
		exit_win(game);
	}
}

void	exit_down(t_game *game)
{
	if (game->c == game->count_c)
	{
		game->count_mov++;
		game->player[0]++;
		exit_win(game);
	}
}

void	exit_left(t_game *game)
{
	if (game->c == game->count_c)
	{
		game->player[1]--;
		game->count_mov++;
		exit_win(game);
	}
}

void	exit_right(t_game *game)
{
	if (game->c == game->count_c)
	{
		game->count_mov++;
		game->player[1]++;
		exit_win(game);
	}
}
