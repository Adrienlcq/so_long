/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_dofi_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:59:31 by adlecler          #+#    #+#             */
/*   Updated: 2022/05/25 16:28:37 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	first_mov_dofi(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
	game->texts_img[3], game->dofi[1] * 32, game->dofi[0] * 32);
}

void	ft_up_dofi(t_game *game)
{
	if (game->map[game->dofi[0] - 1][game->dofi[1]] == '1')
		return ;
	else if (game->map[game->dofi[0] - 1][game->dofi[1]] == 'C')
		game->dofi[0]--;
	else if (game->map[game->dofi[0] - 1][game->dofi[1]] == '0')
		game->dofi[0]--;
	else if (game->map[game->dofi[0] - 1][game->dofi[1]] == 'E')
		return ;
}

void	ft_down_dofi(t_game *game)
{
	if (game->map[game->dofi[0] + 1][game->dofi[1]] == '1')
		return ;
	else if (game->map[game->dofi[0] + 1][game->dofi[1]] == 'C')
		game->dofi[0]++;
	else if (game->map[game->dofi[0] + 1][game->dofi[1]] == '0')
		game->dofi[0]++;
	else if (game->map[game->dofi[0] + 1][game->dofi[1]] == 'E')
		return ;
}

void	ft_left_dofi(t_game *game)
{
	if (game->map[game->dofi[0]][game->dofi[1] - 1] == '1')
		return ;
	else if (game->map[game->dofi[0]][game->dofi[1] - 1] == 'C')
		game->dofi[1]--;
	else if (game->map[game->dofi[0]][game->dofi[1] - 1] == '0')
		game->dofi[1]--;
	else if (game->map[game->dofi[0]][game->dofi[1] - 1] == 'E')
		return ;
}

void	ft_right_dofi(t_game *game)
{
	if (game->map[game->dofi[0]][game->dofi[1] + 1] == '1')
		return ;
	else if (game->map[game->dofi[0]][game->dofi[1] + 1] == 'C')
		game->dofi[1]++;
	else if (game->map[game->dofi[0]][game->dofi[1] + 1] == '0')
		game->dofi[1]++;
	else if (game->map[game->dofi[0]][game->dofi[1] + 1] == 'E')
		return ;
}