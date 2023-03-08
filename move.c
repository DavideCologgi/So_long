/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:54:07 by dcologgi          #+#    #+#             */
/*   Updated: 2024/02/28 09:54:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_touch(t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos] == 'N')
	{
		ft_putstr("YOU LOSE\n");
		exit_game(game);
	}
}

void	grab_collectible(t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos] == 'C')
	{
		game->collectible--;
		game->map[game->pgr_pos][game->pgc_pos] = '0';
	}
	if (game->collectible == 0)
	{
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"./imgs/apple_tree.xpm", &game->img_width, &game->img_height);
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			game->exitc_pos * 64, game->exitr_pos * 64);
	}
	return ;
}

int	pg_move(int keycode, t_data *game)
{
	game->counter = game->move_counter;
	if (keycode == 13)
		move_up(game);
	if (keycode == 1)
		move_down(game);
	if (keycode == 0)
		move_left(game);
	if (keycode == 2)
		move_right(game);
	if (keycode == 53)
		exit_game(game);
	grab_collectible(game);
	enemy_touch(game);
	display_counter(game);
	return (0);
}
