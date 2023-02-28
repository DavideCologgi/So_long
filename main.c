/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:27:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/28 16:47:01 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_data));
	check_map(game, argv);
	render_imgs(game);
	game->mlx = mlx_init();
	game->win= mlx_new_window(game->mlx, 1920, 1080, "Eden's Snake");
	map_gen(game);
	game_exe(game);
	mlx_key_hook(game->win, keypressed, &game);
	mlx_hook(game->win, 2, 1L<<0, ESC_close, &game);
	mlx_hook(game->win, 17, 0, redx_close, &game);
	mlx_loop(game->mlx);
	return (0);
}
