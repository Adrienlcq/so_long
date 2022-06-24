/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:42:01 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/24 10:44:53 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"

# define TEXTURES "txt/P.xpm txt/C1.xpm txt/C2.xpm txt/E.xpm txt/Path.xpm "
# define TEXTURES2 "txt/Wall.xpm txt/dofi.xpm"
# define COMPTEUR "txt/0.xpm txt/1.xpm txt/2.xpm txt/3.xpm txt/4.xpm "
# define COMPTEUR2 "txt/5.xpm txt/6.xpm txt/7.xpm txt/8.xpm txt/9.xpm"

typedef struct s_numbers
{
	void	*text_number[10];
	int		text_numbers_x[10];
	int		text_numbers_y[10];
}			t_numbers;

typedef struct s_game
{
	int			player[2];
	int			dofi[2];
	void		*img;
	int			count_c;
	int			count_mov;
	char		**map;
	int			x_max;
	int			y_max;
	int			x;
	int			y;
	int			c;
	int			p;
	int			e;
	int			d;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	void		*texts_img[7];
	int			text_x[7];
	int			text_y[7];
	int			count;
	t_numbers	numbers;
}			t_game;

int		ft_check_ber(char *file);
int		ft_check_file(char *file);
int		ft_parsing(t_game *game, char *file);
int		ft_check_map_size(t_game *game);
int		ft_map_is_closed(t_game *game);
int		ft_map_is_closed2(t_game *game);
int		ft_check_char_map(t_game *game);
void	ft_init_struct(t_game *game);
int		load_texture(t_game *game);
int		load_textures_numbers(t_game *game);
int		ft_drawing(t_game *game);
void	free_tab2d(char **tab);
int		events_key_manager(int keycode, t_game *game);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
void	first_mov(t_game *game);
int		echap_game_mouse(t_game *game);
void	first_mov_dofi(t_game *game);
void	ft_up_dofi(t_game *game);
void	ft_down_dofi(t_game *game);
void	ft_left_dofi(t_game *game);
void	ft_right_dofi(t_game *game);
void	exit_lose(t_game *game);
void	exit_win(t_game *game);
void	draw_count(t_game *game);

void	exit_up(t_game *game);
void	exit_down(t_game *game);
void	exit_left(t_game *game);
void	exit_right(t_game *game);

#endif