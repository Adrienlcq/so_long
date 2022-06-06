/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:06:36 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/06 14:53:59 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	beginning_events_key_manager(int keycode, t_game *game)
{
	first_mov(game);
	if (game->d == 1)
		first_mov_dofi(game);
	if (keycode == 65307)
		echap_game_mouse(game);
	if (keycode == 119)
	{
		ft_up(game);
		if (game->d == 1)
			ft_up_dofi(game);
	}
}

int	events_key_manager(int keycode, t_game *game)
{
	beginning_events_key_manager(keycode, game);
	if (keycode == 115)
	{	
		ft_down(game);
		if (game->d == 1)
			ft_down_dofi(game);
	}
	if (keycode == 97)
	{	
		ft_left(game);
		if (game->d == 1)
			ft_left_dofi(game);
	}
	if (keycode == 100)
	{
		ft_right(game);
		if (game->d == 1)
			ft_right_dofi(game);
	}
	return (0);
}

int	echap_game_mouse(t_game *game)
{
	write(1, "You quit the game !\n", 20);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img);
	free_tab2d(game->map);
	exit(0);
}
