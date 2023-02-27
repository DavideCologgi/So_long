/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:27:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/27 15:55:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	*game;

	game = (t_data *)malloc(sizeof(t_data));
	game->map = "./maps/map1.ber";
	check_map(game, game->map);
	render_images(game);
	game->mlx = mlx_init();
	game->win= mlx_new_window(game->mlx, 1920, 1080, "");
	map_gen(game, game->map);
	mlx_hook(game->win, 2, 1L<<0, ESC_close, &game);
	mlx_hook(game->win, 17, 0, redx_close, &game);
	mlx_loop(game->mlx);
	return (0);
}
