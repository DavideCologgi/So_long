/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:34 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/06 16:02:52 by dcologgi         ###   ########.fr       */
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

void	display_counter(t_data *game)
{
	char	*move_counter;

	move_counter = ft_itoa(game->move_counter);
	mlx_string_put(game->mlx, game->win, 0, 0, 0xFFFFFF, "Mosse effettuate: ");
	mlx_string_put(game->mlx, game->win, 0, 0, 0xFFFFFF, move_counter);
}
