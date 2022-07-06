/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:18:15 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/06 14:48:58 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	dofi_catch_up(t_game *game)
{
	if (game->dofi[0] - 1 == game->player[0]
		&& game->player[1] == game->dofi[1])
	{
		game->player[0]--;
		write(1, "You were caught by Dofi\n", 24);
		exit_lose(game);
	}
	else
		return ;
}

void	dofi_catch_down(t_game *game)
{
	if (game->dofi[0] + 1 == game->player[0]
		&& game->player[1] == game->dofi[1])
	{
		game->player[0]++;
		write(1, "You were caught by Dofi\n", 24);
		exit_lose(game);
	}
	else
		return ;
}

void	dofi_catch_left(t_game *game)
{
	if (game->player[0] == game->dofi[0]
		&& game->dofi[1] - 1 == game->player[1])
	{
		game->player[1]--;
		write(1, "You were caught by Dofi\n", 24);
		exit_lose(game);
	}
	else
		return ;
}

void	dofi_catch_right(t_game *game)
{
	if (game->player[0] == game->dofi[0]
		&& game->dofi[1] + 1 == game->player[1])
	{
		game->player[1]++;
		write(1, "You were caught by Dofi\n", 24);
		exit_lose(game);
	}
	else
		return ;
}
