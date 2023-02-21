/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:12:25 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/21 14:32:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "./mlx/mlx.h"
#include "./Supreme_Libft/libft.h"
#include "./get_next_line.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
} t_vars;

typedef struct s_data {
	void	*img;
	void	*addr;
	char	**maps;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
} t_data;

int	ESC_close(int keycode, t_vars *vars);
int	redx_close();

#endif
