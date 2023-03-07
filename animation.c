/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:56:21 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/07 15:28:47 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_array(t_data *game)
{
	game->enemy_sprite[0] = mlx_xpm_file_to_image(game->mlx,
				"./imgs/enemysprite1.xpm",&game->img_width, &game->img_height);
	game->enemy_sprite[1] = mlx_xpm_file_to_image(game->mlx,
				"./imgs/enemysprite2.xpm",&game->img_width, &game->img_height);
	game->enemy_sprite[2] = mlx_xpm_file_to_image(game->mlx,
				"./imgs/enemysprite3.xpm",&game->img_width, &game->img_height);
	game->enemy_sprite[3] = mlx_xpm_file_to_image(game->mlx,
				"./imgs/enemysprite4.xpm",&game->img_width, &game->img_height);
}

int	enemy_loop(t_data *game)
{
	int	c;
	int	r;

	game->sprite_counter = 1;
	r = 0;
	map_gen(game);
	while (r < game->vwall_len)
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'N')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy_sprite[game->sprite_counter], c * 64, r * 64);
			}
			c++;
		}
		r++;
	}
	game->sprite_counter = (game->sprite_counter + 1) % 4;
	mlx_destroy_image(game->mlx, game->enemy_sprite[game->sprite_counter]);
	return (0);
}
