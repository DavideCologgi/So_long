/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:24:54 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/27 19:25:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_images(t_data *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./",
	 &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./",
	 &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./",
	 &game->img_width, &game->img_height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./",
	 &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./",
	 &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "./",
	 &game->img_width, &game->img_height);
	return ;
}

void	map_gen(t_data *game, char **map)
{
	int		c;
	int		r;

	r = 0;
	while (r < game->vwall_len)
	{
		c = 0;
		while (c < game->hwall_len)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				c * 63, r * 63);
			if (map[r][c] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
					c * 63, r * 63);
			if (map[r][c] == 'P'){
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					c * 63, r * 63);
				pgr_pos = r;
				pgc_pos = c;
			}
			if (map[r][c] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
					c * 63, r * 63);
			if (map[r][c] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, c * 63, r * 63);
			c++;
		}
		r++;
	}
	return ;
}
