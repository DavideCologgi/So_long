/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:12:25 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/08 14:28:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx/mlx.h"
# include "./get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_data {
	void			*img_player;
	void			*img_wall;
	void			*img_floor;
	void			*img_enemy;
	void			*img_exit;
	void			*img_collectible;
	void			*mlx;
	void			*win;
	char			**map;
	unsigned int	move_counter;
	unsigned int	counter;
	int				img_width;
	int				img_height;
	int				vwall_len;
	int				hwall_len;
	int				player;
	int				exit;
	int				collectible;
	int				enemy;
	int				loop;
	int				pgr_pos;
	int				pgc_pos;
	int				fd;
}	t_data;

int		ft_putstr(char *str);
int		ft_putunbr(unsigned int nb);
int		exit_game(t_data *game);
int		open_map(t_data *game, char **argv);
int		check_vertical_walls(t_data *game);
int		check_horizontal_walls(t_data *game);
int		pg_move(int keycode, t_data *game);
int		enemy_loop(t_data *game);
void	ft_putchar(char c);
void	count_objects(t_data *game, int height, int width);
void	render_imgs(t_data *game);
void	animation_array(t_data *game);
void	map_gen(t_data *game);
void	grab_collectible(t_data *game);
void	enemy_touch(t_data *game);
void	check_map(t_data *game);
void	check_objects(t_data *game);
void	move_up(t_data *game);
void	move_down(t_data *game);
void	move_left(t_data *game);
void	move_right(t_data *game);
void	draw_people(t_data *game, int r, int c);
void	draw_object(t_data *game, int r, int c);
void	draw_wall(t_data *game, int r, int c);
void	draw_floor(t_data *game, int r, int c);
void	display_counter(t_data *game);
void	clean_string(t_data *game);
void	*ft_memset(void *b, int c, size_t length);
char	*ft_itoa(int n);

#endif
