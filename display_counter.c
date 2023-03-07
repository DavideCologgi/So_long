/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:34 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/07 15:41:31 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len] = 48 + (number % 10);
		number = number / 10;
		len--;
	}
	return (s);
}

static long int	ft_nlen(int n)
{
	int	nlen;

	nlen = 0;
	if (n <= 0)
		nlen = 1;
	while (n != 0)
	{
		nlen++;
		n = n / 10;
	}
	return (nlen);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	long int		len;
	unsigned int	number;

	len = ft_nlen(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	len--;
	if (n == 0)
		itoa[0] = '0';
	if (n < 0)
	{
		number = -n;
		itoa[0] = '-';
	}
	else
		number = n;
	itoa = ft_char(itoa, number, len);
	return (itoa);
}

void	clean_string(t_data *game)
{
	void	*img_ptr;
	char	*img_data;
	int		size_line;
	int		endian;
	int		bits_per_pixel;

	img_ptr = mlx_new_image(game->mlx, game->hwall_len * 64, 64);
	img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel,
			&size_line, &endian);
	ft_memset(img_data, 0, game->hwall_len * 64 * (bits_per_pixel / 8));
	mlx_put_image_to_window(game->mlx, game->win, img_ptr,
		0, game->vwall_len * 64);
}

void	display_counter(t_data *game)
{
	char	*smove_counter;

	clean_string(game);
	smove_counter = ft_itoa(game->move_counter);
	mlx_string_put(game->mlx, game->win, 10, ((game->vwall_len + 1) * 64) - 30,
		0xFF0000, "MOSSE EFFETTUATE: ");
	mlx_string_put(game->mlx, game->win, 150, ((game->vwall_len + 1) * 64) - 30,
		0xFF0000, smove_counter);
	if (game->move_counter != game->counter)
	{
		printf("%s", "Mosse effettuate: ");
		printf("%d\n", game->move_counter);
	}
	free(smove_counter);
}
