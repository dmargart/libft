/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:16:40 by dmargart          #+#    #+#             */
/*   Updated: 2020/10/31 16:45:04 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t k;

	j = ft_strlen(dst);
	k = j;
	i = 0;
	if (dstsize <= j)
		return (dstsize + ft_strlen(src));
	if (dstsize && k < dstsize)
	{
		while (src[i] != '\0' && i < dstsize - k - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i + k);
}
