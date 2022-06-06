/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:55:58 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/03 15:13:42 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_texture(t_game *game)
{
	char	**textures;
	int		i;

	i = 0;
	textures = ft_split(TEXTURES, ' ');
	if (textures == NULL)
		return (-1);
	while (i < 5)
	{
		game->texts_img[i] = mlx_xpm_file_to_image(game->mlx, textures[i],
				&game->text_x[i], &game->text_y[i]);
		if (game->texts_img[i] == NULL)
		{
			write(2, "Error during textures load\n", 27);
			free_tab2d(game->map);
			free_tab2d(textures);
			return (-1);
		}
		i++;
	}
	free_tab2d(textures);
	return (0);
}
