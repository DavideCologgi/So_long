/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:27:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/20 16:10:27 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}					t_data;

int	main(void)
{
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	int		width;
	int		height;

	width = 630;
	height = 480;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "Hello World!");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "Mappa_test.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
