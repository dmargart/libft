/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:04:56 by dmargart          #+#    #+#             */
/*   Updated: 2020/11/03 11:54:40 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return ((void *)s + i);
		i++;
	}
	return (0);
}
