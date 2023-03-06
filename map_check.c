/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:47:44 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/06 11:30:20 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_shape(t_data *game)
{
	if (game->hwall_len - 1 == game->vwall_len)
	{
		perror("Mappa non rettangolare");
		exit_game(game);
	}
}

static void	check_walls(t_data *game)
{
	int	horizontal_walls;
	int	vertical_walls;

	horizontal_walls = check_horizontal_walls(game);
	vertical_walls = check_vertical_walls(game);
	if (!horizontal_walls || !vertical_walls)
	{
		perror("Errore bordi mappa");
		exit_game(game);
	}
}

void	check_objects(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->vwall_len - 1)
	{
		j = 0;
		while (j < game->hwall_len)
		{
			count_objects(game, i, j);
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->enemy == 0 || game->exit != 1
		|| game->collectible == 0)
	{
		perror("Errore oggetti mappa");
		exit_game(game);
	}
}

void	check_map(t_data *game)
{
	check_walls(game);
	check_shape(game);
	check_objects(game);
}
