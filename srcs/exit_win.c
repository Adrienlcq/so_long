/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:12:34 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/06 13:08:29 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_win(t_game *game)
{
	int	i;

	i = -1;
	write(1, "You win !\n", 10);
	while (++i < 5)
		mlx_destroy_image(game->mlx, game->texts_img[i]);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free_tab2d(game->map);
	free(game->mlx);
	exit(0);
}
