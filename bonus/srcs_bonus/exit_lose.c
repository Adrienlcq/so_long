/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_lose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:21:58 by mqueguin          #+#    #+#             */
/*   Updated: 2022/06/03 15:20:39 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	exit_lose(t_game *game)
{
	printf("You lost !\n");
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_tab2d(game->map);
	exit(0);
}