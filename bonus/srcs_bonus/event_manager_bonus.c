/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:06:36 by adlecler          #+#    #+#             */
/*   Updated: 2022/05/25 16:26:42 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	events_key_manager(int keycode, t_game *game)
{
	first_mov(game);
	first_mov_dofi(game);
	if (keycode == 65307)
		echap_game_mouse(game);
	if (keycode == 119)
	{
		ft_up(game);
		ft_up_dofi(game);
	}
	if (keycode == 115)
	{	
		ft_down(game);
		ft_down_dofi(game);
	}
	if (keycode == 97)
	{	
		ft_left(game);
		ft_left_dofi(game);
	}
	if (keycode == 100)
	{
		ft_right(game);
		ft_right_dofi(game);
	}
	return (0);
}

int	echap_game_mouse(t_game *game)
{
	printf("You quit the game !\n");
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img);
	free_tab2d(game->map);
	exit(0);
}