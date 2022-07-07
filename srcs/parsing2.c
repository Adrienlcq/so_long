/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:44:16 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/03 16:55:42 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	char_map(t_game *game)
{
	while (game->x <= game->x_max)
	{
		if (game->map[game->y][game->x] != '0' &&
				game->map[game->y][game->x] != '1' &&
					game->map[game->y][game->x] != 'C' &&
						game->map[game->y][game->x] != 'E' &&
							game->map[game->y][game->x] != 'P')
		{
			write(2, "Error\nInvalid character in map\n", 31);
			return (-1);
		}
		if (game->map[game->y][game->x] == 'P')
		{
			game->p++;
			game->player[0] = game->y;
			game->player[1] = game->x;
		}
		if (game->map[game->y][game->x] == 'C')
			game->c++;
		if (game->e == 0 && game->map[game->y][game->x] == 'E')
			game->e = 1;
		game->x++;
	}
	return (0);
}

int	ft_check_char_map(t_game *game)
{
	while (game->y <= game->y_max)
	{
		if (char_map(game) == -1)
			return (-1);
		game->x = 0;
		game->y++;
	}
	if (game->p != 1)
	{
		write(2, "Error\nMissing player or there is more than one player\n", 55);
		return (-1);
	}
	if (game->e != 1)
	{
		write(2, "Error\nMissing exit or there is more than one exit\n", 50);
		return (-1);
	}
	if (game->c < 1)
	{
		write(2, "Error\nMissing collectible\n", 27);
		return (-1);
	}
	return (0);
}
