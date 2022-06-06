/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:03:42 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/03 17:05:24 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (0);
	return (-1);
}

int	ft_check_file(char *file)
{
	int	fd;

	fd = open(file, 0);
	if (fd < 0)
		return (-1);
	return (0);
}

void	ft_init_struct(t_game *game)
{
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->count_c = 0;
	game->count_mov = 0;
	game->x = 0;
	game->y = 0;
}

void	free_tab2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
