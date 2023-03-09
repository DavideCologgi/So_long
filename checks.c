/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:42:42 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/09 10:47:54 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_objects(t_data *game, int height, int width)
{
	if (game->map[height][width] != '1' && game->map[height][width] != '0'
		&& game->map[height][width] != 'P' && game->map[height][width] != 'C'
		&& game->map[height][width] != 'E' && game->map[height][width] != 'N'
		&& game->map[height][width] != '\n')
	{
		ft_putstr("Oggetto non definito in mappa\n");
		exit_game(game);
	}
	if (game->map[height][width] == 'P')
		game->player++;
	if (game->map[height][width] == 'E')
		game->exit++;
	if (game->map[height][width] == 'C')
		game->collectible++;
	if (game->map[height][width] == 'N')
		game->enemy++;
}

int	check_vertical_walls(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->vwall_len)
	{
		if (!(game->map[i][0] == '1'
			&& game->map[i][game->hwall_len - 1] == '1'))
			return (0);
		i++;
	}
	return (1);
}

int	check_horizontal_walls(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->hwall_len)
	{
		if (!(game->map[0][i] == '1'
			&& game->map[game->vwall_len - 1][i] == '1'))
			return (0);
		i++;
	}
	return (1);
}
