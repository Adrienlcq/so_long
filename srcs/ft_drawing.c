/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:47:21 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/03 16:31:03 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_drawing2(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[4], x * 32, y * 32);
	else if (y == game->player[0] && x == game->player[1])
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[0], game->player[1] * 32,
			game->player[0] * 32);
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
}

int	ft_drawing(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			ft_drawing2(game, x, y);
		}
	}
	return (0);
}
