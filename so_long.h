/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:12:25 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/27 16:02:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "./mlx/mlx.h"
#include "./Supreme_Libft/libft.h"
#include "./get_next_line.h"

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
	int		vwall_len;
	int		hwall_len;
	int		player;
	int		exit;
	int		collectible;
	int		pgr_pos;
	int		pgc_pos;
} t_data;

int	ESC_close(int keycode, t_data *game);
int	redx_close();

#endif
