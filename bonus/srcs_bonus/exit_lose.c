/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_lose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:21:58 by mqueguin          #+#    #+#             */
/*   Updated: 2022/07/06 13:09:58 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	exit_lose(t_game *game)
{
	int	i;

	i = -1;
	write(1, "You lost !\n", 11);
	while (++i < 10)
		mlx_destroy_image(game->mlx, game->numbers.text_number[i]);
	i = -1;
	while (++i < 7)
		mlx_destroy_image(game->mlx, game->texts_img[i]);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free_tab2d(game->map);
	free(game->mlx);
	exit(0);
}
