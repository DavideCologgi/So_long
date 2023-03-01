/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:12:25 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/01 15:02:32 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "./minilibx/mlx.h"
#include "./get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

typedef struct s_data {
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_enemy;
	void	*img_exit;
	void	*img_collectible;
	void	*mlx;
	void	*win;
	char	**map;
	int		move_counter;
	int		img_width;
	int		img_height;
	int		vwall_len;
	int		hwall_len;
	int		player;
	int		exit;
	int		collectible;
	int		enemy;
	int		pgr_pos;
	int		pgc_pos;
	int		fd;
} t_data;

int			exit_game(t_data *game);
int			open_map(t_data *game, char **argv);
int			keypressed(int	key_pressed, t_data *game);
void		pg_move(t_data *game, int key_pressed);
void		render_imgs(t_data *game);
void		map_gen(t_data *game);
void		grab_collectible(t_data *game);
void		enemy_touch(t_data *game);
void		check_map(t_data *game);
void		check_objects(t_data *game);

#endif
