/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:47:21 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/06 10:56:22 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	ft_animation(t_game *game, int x, int y)
{
	static int	i = 0;

	if (i < 500)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[1], x * 32, y * 32);
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[2], x * 32, y * 32);
	}
	i++;
	if (i == 1000)
		i = 0;
}

void	ft_drawing2(t_game *game, int x, int y)
{
	if (y == game->dofi[0] && x == game->dofi[1])
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[6], game->dofi[1] * 32, game->dofi[0] * 32);
	}
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[5], x * 32, y * 32);
	else if (y == game->player[0] && x == game->player[1])
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[0], game->player[1] * 32,
			game->player[0] * 32);
	}
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[4], x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[3], x * 32, y * 32);
	else if (game->map[y][x] == 'C')
	{
		ft_animation(game, x, y);
	}
}

int	ft_drawing(t_game *game)
{
	int			x;
	int			y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			ft_drawing2(game, x, y);
			draw_count(game);
		}
	}
	return (0);
}
