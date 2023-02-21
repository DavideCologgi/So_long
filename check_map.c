/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:51:56 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/21 17:00:42 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*check_restof_map(int fd, char *line, t_data *game)
{
	int		i;
	char	*last;

	i = 0;
	while (1)
	{
		if (game->hwall_len != ft_strlen(line) || line[0] != 49 || line[ft_strlen(line - 2)] != 49)
		{
			write(1, "Error\n", 6);
			perror("Mappa non rettangolare");
			exit (0);
		}
		last = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	game->vwall_len = i;
	return (last);
}

static void	check_first_line(int fd, t_data *game)
{
	char	*line;
	char	*last_line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	game->hwall_len = ft_strlen(line);
	while (line[i] == '1')
		i++;
	if (!(line[i] == '\n' && line[i + 1] == 0))
		game->error = 1;
	last_line = check_restof_map(fd, line, game);
	if (game->hwall_len == -1)
		game->error = 1;
	i = 0;
	while (last_line[i] == 1)
		i++;
	if (!(last_line[i] == '\n' && line[i + 1] == 0))
		game->error = 1;
	game->vwall_len = game->hwall_len - 1;
	free(last_line);
	return ;
}

void	check_map(char *map, t_data *game)
{
	int	fd;

	fd = open(map, O_RDONLY);
	check_first_line(fd, game);
	close(fd);
	return ;
}
