/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:27:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/09 10:45:37 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_format(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e'
		&& argv[i - 2] == 'b' && argv[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc == 2)
	{
		if (!check_map_format(argv[1]))
		{
			ft_putstr("File mappa non .ber\n");
			exit(0);
		}
		ft_memset(&game, 0, sizeof(t_data));
		open_map(&game, argv);
		check_map(&game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.hwall_len * 64,
				(game.vwall_len + 1) * 64, "Eden's Snake");
		render_imgs(&game);
		map_gen(&game);
		mlx_key_hook(game.win, pg_move, &game);
		mlx_hook(game.win, 17, 0, exit_game, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
