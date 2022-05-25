/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:47:21 by adlecler          #+#    #+#             */
/*   Updated: 2022/05/25 16:11:36 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	ft_drawing(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->texts_img[4], x * 32, y * 32);
			else if (y == game->player[0] && x == game->player[1])
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->texts_img[0], game->player[1] * 32, game->player[0] * 32);
			}
			else if (y == game->dofi[0] && x == game->dofi[1])
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->texts_img[5], game->dofi[1] * 32, game->dofi[0] * 32);
			}
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->texts_img[3], x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->texts_img[1], x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->texts_img[2], x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}
