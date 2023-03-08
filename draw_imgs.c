/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:05:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/08 13:40:51 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_people(t_data *game, int r, int c)
{
	if (game->map[r][c] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			c * 64, r * 64);
		game->pgr_pos = r;
		game->pgc_pos = c;
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy,
			c * 64, r * 64);
}

void	draw_object(t_data *game, int r, int c)
{
	if (game->map[r][c] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			c * 64, r * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible, c * 64, r * 64);
}

void	draw_wall(t_data *game, int r, int c)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
		c * 64, r * 64);
}

void	draw_floor(t_data *game, int r, int c)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
		c * 64, r * 64);
}
