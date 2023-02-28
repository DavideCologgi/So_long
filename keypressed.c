/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:54:07 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/28 09:54:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pg_move(t_data *game, int key_pressed, int move_counter)
{
	if (key_pressed == 13 && game->map[game->pgr_pos - 1][game->pgc_pos] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 63, game->pgr_pos * 63);
		game->pgr_pos--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 63, game->pgr_pos *63);
		move_counter++;
	}
	if (key_pressed == 1 && game->map[game->pgr_pos + 1][game->pgc_pos] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 63, game->pgr_pos * 63);
		game->pgr_pos++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 63, game->pgr_pos *63);
		move_counter++;
		}
	if (key_pressed == 0 && game->map[game->pgr_pos][game->pgc_pos - 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 63, game->pgr_pos * 63);
		game->pgc_pos--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 63, game->pgr_pos *63);
		move_counter++;
	}
	if (key_pressed == 2 && game->map[game->pgr_pos][game->pgc_pos + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 63, game->pgr_pos * 63);
		game->pgc_pos++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 63, game->pgr_pos *63);
		move_counter++;
	}
	printf("%d\n", move_counter);
	return ;
}

void	keypressed(t_data *game)
{
	int			key_pressed;
	static int	move_counter;

	move_counter = 0;
	while (game->map[game->pgr_pos][game->pgc_pos] != 'E'
		&& game->collectible == 0)
			pg_move(game, key_pressed, move_counter);
	printf("%s\n", "YOU WIN");
	return ;
}
