/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:59:24 by dmargart          #+#    #+#             */
/*   Updated: 2020/10/31 20:55:01 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (haystack[j] != '\0' && j + i < len + 1)
	{
		if (ft_strchr(&(haystack[j]), needle[0]))
		{
			if (!(ft_strncmp(&(haystack[j]), needle, i)))
				return (&((char *)haystack)[j]);
		}
		j++;
	}
	return (NULL);
}
