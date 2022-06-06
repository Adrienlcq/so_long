/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:20:22 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/06 12:16:13 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	check_invalid_char(t_game *game)
{
	if (game->map[game->y][game->x] != '0' &&
			game->map[game->y][game->x] != '1' &&
				game->map[game->y][game->x] != 'C' &&
					game->map[game->y][game->x] != 'E' &&
						game->map[game->y][game->x] != 'P' &&
							game->map[game->y][game->x] != 'D')
	{
		printf("Error, invalid character in map\n");
		return (-1);
	}
	return (0);
}

int	char_map(t_game *game)
{
	while (game->x <= game->x_max)
	{
		check_invalid_char(game);
		if (game->map[game->y][game->x] == 'P')
		{
			game->p++;
			game->player[0] = game->y;
			game->player[1] = game->x;
		}
		if (game->map[game->y][game->x] == 'D')
		{
			game->d++;
			game->dofi[0] = game->y;
			game->dofi[1] = game->x;
			game->map[game->y][game->x] = '0';
		}
		if (game->map[game->y][game->x] == 'C')
			game->c++;
		if (game->e == 0 && game->map[game->y][game->x] == 'E')
			game->e = 1;
		game->x++;
	}
	return (0);
}

int	beginning_check_char_map(t_game *game)
{
	while (game->y <= game->y_max)
	{
		if (char_map(game) == -1)
			return (-1);
		game->x = 0;
		game->y++;
	}
	return (0);
}

int	ft_check_char_map(t_game *game)
{
	beginning_check_char_map(game);
	if (game->p != 1)
	{
		printf("Error\nMissing player or there is more than one player\n");
		return (-1);
	}
	if (game->e != 1)
	{
		printf("Error\nMissing exit or there is more than one exit\n");
		return (-1);
	}
	if (game->c < 1)
	{
		printf("Error\nMissing collectible\n");
		return (-1);
	}
	if (game->d > 1)
	{
		printf("Error\nThere is more than one Dofi\n");
		return (-1);
	}
	return (0);
}
