/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:06:36 by adlecler          #+#    #+#             */
/*   Updated: 2022/05/25 13:39:20 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	events_key_manager(int keycode, t_game *game)
{
	first_mov(game);
	if (keycode == 65307)
		echap_game_mouse(game);
	if (keycode == 119)
		ft_up(game);
	if (keycode == 115)
		ft_down(game);
	if (keycode == 97)
		ft_left(game);
	if (keycode == 100)
		ft_right(game);
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