/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:47:44 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/01 13:08:52 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_shape(t_data *game)
{
	if (game->hwall_len == game->vwall_len)
	{
		perror("Mappa non rettangolare");
		exit_game(game);
	}
}

static int	check_horizontal_walls(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->hwall_len)
	{
		if (!(game->map[0][i] == '1' &&
			game->map[game->vwall_len - 1][i] == '1'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_vertical_walls(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->vwall_len)
	{
		if (!(game->map[i][0] == '1' &&
			game->map[i][game->hwall_len - 1] == '1'))
			return (0);
		i++;
	}
	return (1);
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

static void	count_objects(t_data *game, int height, int width)
{
	if (game->map[height][width] != '1' && game->map[height][width] != '0' &&
		game->map[height][width] != 'P' && game->map[height][width] != 'C' &&
		game->map[height][width] != 'E' && game->map[height][width] != 'N' &&
		game->map[height][width] != '\n')
	{
		perror("Oggetto non definito in mappa");
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
	if (game->player != 1 || game->enemy == 0 || game->exit != 1 ||
		game->collectible == 0)
	{
		perror("Errore oggetti mappa");
		exit_game(game);
	}
}

void	check_map(t_data *game)
{
	check_shape(game);
	check_walls(game);
	check_objects(game);
}
