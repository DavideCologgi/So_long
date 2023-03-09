/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pg_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:47:22 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/09 10:47:59 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *game)
{
	if (game->map[game->pgr_pos - 1][game->pgc_pos] == 'E'
		&& game->collectible == 0)
	{
		ft_putstr("YOU WIN\n");
		exit_game(game);
	}
	if (game->map[game->pgr_pos - 1][game->pgc_pos] != '1'
		&& game->map[game->pgr_pos - 1][game->pgc_pos] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgr_pos--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
}

void	move_down(t_data *game)
{
	if (game->map[game->pgr_pos + 1][game->pgc_pos] == 'E'
		&& game->collectible == 0)
	{
		ft_putstr("YOU WIN\n");
		exit_game(game);
	}
	if (game->map[game->pgr_pos + 1][game->pgc_pos] != '1'
		&& game->map[game->pgr_pos + 1][game->pgc_pos] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgr_pos++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
}

void	move_left(t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos - 1] == 'E'
		&& game->collectible == 0)
	{
		ft_putstr("YOU WIN\n");
		exit_game(game);
	}
	if (game->map[game->pgr_pos][game->pgc_pos - 1] != '1'
		&& game->map[game->pgr_pos][game->pgc_pos - 1] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgc_pos--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
}

void	move_right(t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos + 1] == 'E'
		&& game->collectible == 0)
	{
		ft_putstr("YOU WIN\n");
		exit_game(game);
	}
	if (game->map[game->pgr_pos][game->pgc_pos + 1] != '1'
		&& game->map[game->pgr_pos][game->pgc_pos + 1] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgc_pos++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
}
