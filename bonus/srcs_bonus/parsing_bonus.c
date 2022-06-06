/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:26:38 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/06 11:21:05 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	ft_parsing(t_game *game, char *file)
{
	int		fd;
	char	buffer[5000];
	int		ret;

	fd = open(file, 0);
	ft_bzero(buffer, 5000);
	ret = read(fd, buffer, 5000);
	if (ret < 0)
	{
		write(2, "Error\nRead file\n", 16);
		return (-1);
	}
	if (ret > 4999)
	{
		write(2, "Error\nAbuse pas des bails\n", 26);
		exit(1);
	}
	if (buffer[0] == '\0')
	{
		write(2, "Error\nMap is empty !\n", 21);
		return (-1);
	}
	game->map = ft_split(buffer, '\n');
	return (0);
}

int	ft_check_map_size(t_game *game)
{
	int	len;
	int	new_len;
	int	i;

	i = 1;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		new_len = ft_strlen(game->map[i]);
		if (new_len != len)
		{
			write(2, "Error\nMap size isn't good !\n", 29);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_map_is_closed(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
		{
			write(2, "Error\nTop map isn't closed !\n", 29);
			return (-1);
		}
		i++;
	}
	game->x_max = i - 1;
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
		{
			write(2, "Error\nLeft side of the map isn't closed !\n", 42);
			return (-1);
		}
		i++;
	}
	game->y_max = i - 1;
	return (0);
}

int	ft_map_is_closed2(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->y_max)
	{
		if (game->map[i][game->x_max] != '1')
		{
			write(2, "Error\nRight side of the map isn't closed !\n", 43);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i <= game->x_max)
	{
		if (game->map[game->y_max][i] != '1')
		{
			write(2, "Error\nBottom map isn't closed !\n", 32);
			return (-1);
		}
		i++;
	}
	return (0);
}
