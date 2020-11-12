/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:20:44 by dmargart          #+#    #+#             */
/*   Updated: 2020/11/06 17:02:11 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num(int n)
{
	int	res;
	int	i;

	i = 0;
	res = n;
	if (n <= 0)
		i = 1;
	while (res != 0)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_num(n);
	if (!(str = (char *)malloc((i * sizeof(char) + 1))))
		return (NULL);
	str[i] = '\0';
	if (n == -2147483648)
	{
		n = -214748364;
		str[i-- - 1] = '8';
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (i > 0 && str[i - 1] != '-')
	{
		str[i-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
