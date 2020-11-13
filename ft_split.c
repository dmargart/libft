/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmargart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:14:45 by dmargart          #+#    #+#             */
/*   Updated: 2020/11/13 11:26:56 by dmargart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free(char **arr, int l)
{
	int i;

	i = 0;
	while (i < l - 1)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static	size_t	ft_words(char const *s, char c)
{
	size_t	w;
	size_t	i;

	i = 0;
	w = 0;
	if (c != '\0')
	{
		while (s[i] == c)
			i++;
	}
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c || s[i] == '\0')
		{
			w++;
			while (s[i] == c && s[i] != '\0')
				i++;
		}
	}
	return (w);
}

static	char	*ft_wordup(const char *s1, size_t a, size_t b)
{
	char	*s2;
	size_t	i;

	if (!(s2 = (char *)malloc(b - a + 1)))
		return (NULL);
	i = 0;
	while (a < b)
		s2[i++] = s1[a++];
	s2[i] = '\0';
	return (s2);
}

char			**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		l;
	char		**arr;
	size_t		j;

	if (!s || !(arr = (char **)malloc((ft_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	l = 0;
	j = 0;
	while (l < ft_words(s, c))
	{
		while (s[i++] == c)
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if ((s[i] == c) || s[i] == '\0')
		{
			if (!(arr[l++] = ft_wordup(s, j, i)))
				return (ft_free(arr, l));
		}
		j = i;
	}
	arr[l] = 0;
	return (arr);
}
