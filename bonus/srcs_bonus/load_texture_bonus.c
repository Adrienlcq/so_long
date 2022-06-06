/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:55:58 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/03 15:22:22 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	load_texture(t_game *game)
{
	char	**textures;
	int		i;
	char	*str;

	i = -1;
	str = ft_strjoin(TEXTURES, TEXTURES2);
	textures = ft_split(str, ' ');
	if (textures == NULL)
		return (-1);
	while (++i < 7)
	{
		game->texts_img[i] = mlx_xpm_file_to_image(game->mlx,
				textures[i], &game->text_x[i], &game->text_y[i]);
		if (game->texts_img[i] == NULL)
		{
			printf("Error during textures load\n");
			free_tab2d(game->map);
			free_tab2d(textures);
			free(str);
			return (-1);
		}
	}
	free_tab2d(textures);
	free(str);
	return (0);
}

int	load_textures_numbers(t_game *game)
{
	char	**path;
	int		i;
	char	*str;

	str = ft_strjoin(COMPTEUR, COMPTEUR2);
	path = ft_split(str, ' ');
	i = -1;
	while (++i < 10)
	{
		game->numbers.text_number[i] = mlx_xpm_file_to_image(game->mlx,
				path[i], &game->numbers.text_numbers_x[i],
				&game->numbers.text_numbers_y[i]);
		if (!game->numbers.text_number[i])
		{
			free_tab2d(game->map);
			free_tab2d(path);
			free(str);
			printf("Error\nUnable to load numbers textures\n");
			return (-1);
		}
	}
	free(str);
	free_tab2d(path);
	return (0);
}
