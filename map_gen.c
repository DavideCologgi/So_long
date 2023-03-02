/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:54:17 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/02 16:33:55 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_imgs(t_data *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./imgs/pg_tile.xpm",
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall_tile.xpm",
			&game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./imgs/floor_tile.xpm",
			&game->img_width, &game->img_height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./imgs/enemy_tile.xpm",
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit_tile.xpm",
			&game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./imgs/collectible_tile.xpm", &game->img_width, &game->img_height);
	return ;
}

void	map_gen(t_data *game)
{
	int	c;
	int	r;

	r = 0;
	while (r < game->vwall_len)
	{
		c = 0;
		while (game->map[r][c])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				c * 64, r * 64);
			if (game->map[r][c] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
					c * 64, r * 64);
			if (game->map[r][c] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					c * 64, r * 64);
				game->pgr_pos = r;
				game->pgc_pos = c;
			}
			if (game->map[r][c] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
					c * 64, r * 64);
			if (game->map[r][c] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, c * 64, r * 64);
			if (game->map[r][c] == 'N')
				mlx_put_image_to_window(game->mlx, game->win, game->img_enemy,
					c * 64, r * 64);
			c++;
		}
		r++;
	}
	return ;
}
