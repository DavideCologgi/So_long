/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:12:25 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/28 16:47:01 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "./minilibx/mlx.h"
#include "./get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

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
	int		img_width;
	int		img_height;
	size_t	vwall_len;
	size_t	hwall_len;
	int		player;
	int		exit;
	int		collectible;
	int		pgr_pos;
	int		pgc_pos;
	int		fd;
} t_data;

int			ESC_close(int keycode, t_data *game);
int			redx_close();
void		check_objects(char *last, t_data *game);
char		*check_restof_map(char *line, t_data *game);
void		check_first_line(t_data *game);
void		check_map(t_data *game, char **argv);
void		pg_move(t_data *game, int key_pressed, int move_counter);
void		keypressed(t_data *game);
void		render_imgs(t_data *game);
void		map_gen(t_data *game);
static void	*ft_memset(void *b, int c, size_t length);

#endif
