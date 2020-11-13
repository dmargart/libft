/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:06:45 by dmargart          #+#    #+#             */
/*   Updated: 2020/11/11 15:33:19 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned long	ft_power(int i, int p)
{
	unsigned long	res;

	if (p == 0)
		return (1);
	res = i;
	while (p > 1)
	{
		res = res * i;
		p--;
	}
	return (res);
}

static	int				if_negative(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		return (-n);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	else
		return (n);
}

void					ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		j;
	char	c;

	if ((n = if_negative(n, fd)))
	{
		i = n;
		j = 0;
		while (i != 0)
		{
			i = i / 10;
			j++;
		}
		i = n;
		while (j > 0)
		{
			i = i / ft_power(10, j - 1);
			c = i + 48;
			write(fd, &c, 1);
			j--;
			i = n % (ft_power(10, j));
		}
	}
}
