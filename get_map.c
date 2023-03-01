/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:51:56 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/01 13:05:56 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_width(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if (line[i - 1] == '\n')
		i--;
	return (i);
}

static int	write_map_line(t_data *game, char *line)
{
	char	**map_line;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->vwall_len++;
	map_line = (char **)malloc(sizeof(char *) * (game->vwall_len + 1));
	map_line[game->vwall_len] = NULL;
	while (i < game->vwall_len - 1)
	{
		map_line[i] = game->map[i];
		i++;
	}
	map_line[i] = line;
	if (game->map)
		free(game->map);
	game->map = map_line;
	return (1);
}

int	open_map(t_data *game, char **argv)
{
	char	*read_map;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		read_map = get_next_line(game->fd);
		if (!write_map_line(game, read_map))
			break ;
	}
	close(game->fd);
	game->hwall_len = map_width(game->map[0]);
	return (1);
}
