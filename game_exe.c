/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:29 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 16:03:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_exe(t_data *game, char **map)
{
	char	keypressed;
	int		move_counter;

	keypressed = getch();
	move_counter = 0;
	while (map[pgr_pos][pgc_pos] != 'E')
	{
		if (keypressed == 'w' && map[pgr_pos - 1][pgc_pos]!= '1')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				game->pgc_pos * 63, game->pgr_pos * 63);
			game->pgc_pos--;
			mlx_put_image_to_window(game->mlx, game->win, game->img_player,
				game->pgc_pos * 63, game->pgr_pos *63);
			move_counter++;
		}
		if
	}

}
