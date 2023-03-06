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
		printf("%s\n", "YOU LOSE");
		exit_game(game);
	}
}

void	grab_collectible(t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos] == 'C')
		game->collectible--;
	return ;
}

int	pg_move(int keycode, t_data *game)
{
	if (keycode == 13 && game->map[game->pgr_pos - 1][game->pgc_pos] != '1')
		move_up(game);
	if (keycode == 1 && game->map[game->pgr_pos + 1][game->pgc_pos] != '1')
		move_down(game);
	if (keycode == 0 && game->map[game->pgr_pos][game->pgc_pos - 1] != '1')
		move_left(game);
	if (keycode == 2 && game->map[game->pgr_pos][game->pgc_pos + 1] != '1')
		move_right(game);
	grab_collectible(game);
	enemy_touch(game);
	printf("%i\n", game->move_counter);
	return (1);
}
