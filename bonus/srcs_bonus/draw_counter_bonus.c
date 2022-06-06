/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_counter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:50:36 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/03 15:17:55 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	get_size(int count)
{
	int	size;

	if (count == 0)
		return (1);
	size = 0;
	while (count > 0)
	{
		count /= 10;
		size++;
	}
	return (size);
}

void	draw_count(t_game *game)
{
	int	size;
	int	count;
	int	tmp;

	if (game->count_mov > 999)
	{
		printf("You are bad\n");
		exit_lose(game);
	}
	count = game->count_mov;
	tmp = count;
	size = get_size(count) - 1;
	while (size >= 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->numbers.text_number[(tmp % 10)], size * 32, 0);
		tmp /= 10;
		size--;
	}
}
