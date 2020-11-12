/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:46:31 by dmargart          #+#    #+#             */
/*   Updated: 2020/11/03 16:00:26 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (start < ft_strlen(s))
	{
		if (!(dest = (char *)malloc(len + 1)) || !s)
	                return (NULL);
		while (s[start] != '\0' && i < len)
		{
			dest[i] = s[start];
			i++;
			start++;
		}
		dest[i] = '\0';
		return (dest);
	}
	if (!(dest = (char *)malloc(1)))
		return (NULL);
	dest[0] = '\0';
	return (dest);
}
