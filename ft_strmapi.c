/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:50:19 by dmargart          #+#    #+#             */
/*   Updated: 2020/11/06 12:51:52 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	if (!f || !s || !(s2 = ft_strdup(s)))
		return (0);
	i = 0;
	while (s2[i] != '\0')
	{
		s2[i] = f(i, s2[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
