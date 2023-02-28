/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:51:56 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/28 16:47:01 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_objects(char *last, t_data *game)
{
	size_t	j;

	j = 0;
	while (j < game->hwall_len)
	{
		if (last[j] == 'P')
			game->player += 1;
		if (last[j] == 'E')
			game->exit += 1;
		if (last[j] == 'C')
			game->collectible += 1;
		j++;
	}
	return ;
}
char	*check_restof_map(char *line, t_data *game)
{
	int		i;
	int		j;
	char	*last;

	i = 0;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	while (1)
	{
		if (game->hwall_len + 2 != (ft_strlen(line)) || line[0] != 49 || line[ft_strlen(line - 2)] != 49)
		{
			perror("Mappa non rettangolare");
			exit (0);
		}
		j = 0;
		last = strdup(line);
		free(line);
		check_objects(last, game);
		i++;
		line = get_next_line(game->fd);
		if (!line)
			break ;
	}
	if (game->player != 1 || game->exit != 1 || game->collectible == 0)
	{
		perror("Errore nel setting degli oggetti di mappa");
		exit (0);
	}
	game->vwall_len = i;
	return (last);
}

void	check_first_line(t_data *game)
{
	char	*line;
	char	*last_line;
	int		i;

	i = 0;
	line = get_next_line(game->fd);
	game->hwall_len = ft_strlen(line) - 2;
	while (line[i] == '1')
		i++;
	if (!(line[i] == '\n' && line[i + 1] == 0))
	{
		perror("Mappa non valida");
		exit (0);
	}
	last_line = check_restof_map(line, game);
	i = 0;
	while (last_line[i] == 1)
		i++;
	if (!(last_line[i] == '\n' && line[i + 1] == 0))
	{
		perror("Mappa non valida");
		exit (0);
	}
	free(last_line);
	return ;
}

void	check_map(t_data *game, char **argv)
{
	game->fd = open(argv[1], O_RDONLY);
	check_first_line(game);
	game->map =
	close(game->fd);
	return ;
}
