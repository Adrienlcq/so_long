/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:26:38 by adlecler          #+#    #+#             */
/*   Updated: 2022/05/25 13:36:33 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		write(2, "Error read file\n", 16);
		return (-1);
	}
	if (ret > 4999)
	{
		write(2, "ERROR: EH TA MERE\n", 18);
		exit(1);
	}
	if (buffer[0] == '\0')
	{
		printf("Error map is empty !\n");
		return (-1);
	}
	game->map = ft_split(buffer, '\n');
	for (int i = 0; game->map[i]; i++)
	{
		printf("%s\n", game->map[i]);
	}
	return (0);
}

// check si la map est bien rectangulaire/carree
// game->map[0] : premiere ligne de la map
int	ft_check_map_size(t_game *game, char *file)
{
	int	len;
	int	new_len;
	int	i;

	(void)file;
	i = 1;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		new_len = ft_strlen(game->map[i]);
		if (new_len != len)
		{
			write(2, "Map size isn't good !\n", 23);
			return (-1);
		}
		i++;
	}
	return (0);
}

// check si la map est entouree de murs
int	ft_map_is_closed(t_game *game, char *file)
{
	int	i;

	(void)file;
	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
		{
			printf("Top map isn't closed !\n");
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
			printf("Left side of the map isn't closed !\n");
			return (-1);
		}
		i++;
	}
	game->y_max = i - 1;
	return (0);
}

int	ft_map_is_closed2(t_game *game, char *file)
{
	int	i;

	(void)file;
	i = 0;
	while (i <= game->y_max)
	{
		if (game->map[i][game->x_max] != '1')
		{
			printf("Right side of the map isn't closed !\n");
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i <= game->x_max)
	{
		if (game->map[game->y_max][i] != '1')
		{
			printf("Bottom map isn't closed !\n");
			return (-1);
		}
		i++;
	}
	printf("Map is closed !\n");
	return (0);
}

int	char_map(t_game *game, char *file)
{
	(void)file;
	while (game->x <= game->x_max)
	{
		if (game->map[game->y][game->x] != '0' &&
				game->map[game->y][game->x] != '1' &&
					game->map[game->y][game->x] != 'C' &&
						game->map[game->y][game->x] != 'E' &&
							game->map[game->y][game->x] != 'P')
		{
			printf("Error, invalid character in map\n");
			return (-1);
		}
		if (game->map[game->y][game->x] == 'P')
		{
			game->p++;
			game->player[0] = game->y; //recupere la position y du player
			game->player[1] = game->x; //recupere la position x du player
		}
		if (game->map[game->y][game->x] == 'C')
			game->c++;
		if (game->e == 0 && game->map[game->y][game->x] == 'E')
			game->e = 1;
		game->x++;
	}
	return (0);
}

// check rien d'autre que 0,1,E,C,P
int	ft_check_char_map(t_game *game, char *file)
{
	while (game->y <= game->y_max)
	{
		if (char_map(game, file) == -1)
			return (-1);
		game->x = 0;
		game->y++;
	}
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
	return (0);
}
