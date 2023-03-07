/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:54:17 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/07 10:19:01 by dcologgi         ###   ########.fr       */
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
			draw_floor(game, r, c);
			if (game->map[r][c] == '1')
				draw_wall(game, r, c);
			else if (game->map[r][c] == 'P' || game->map[r][c] == 'N')
				draw_people(game, r, c);
			else if (game->map[r][c] == 'E' || game->map[r][c] == 'C')
				draw_object(game, r, c);
			c++;
		}
		r++;
	}
	return ;
}
