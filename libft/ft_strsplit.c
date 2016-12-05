/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:05:40 by behamon           #+#    #+#             */
/*   Updated: 2016/11/06 15:48:39 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_fill_str(char const *s, size_t *i, char c)
{
	size_t	len;
	size_t	j;
	char	*str;

	len = 0;
	j = 0;
	while (s[len] != c)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[*i] && s[*i] != c)
	{
		str[j] = s[*i];
		*i += 1;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	last;

	i = 0;
	count = 0;
	if (ft_strlen(s) > 0)
		last = s[0];
	else
		return (0);
	while (i < ft_strlen(s))
	{
		if (s[i] == c && last != c)
			count++;
		last = s[i];
		i++;
	}
	if (count > 0 && last != c)
		count++;
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (s)
	{
		if (!(tab = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1)))
			return (NULL);
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i] && s[i] != c)
			{
				tab[j] = ft_fill_str(s, &i, c);
				j++;
			}
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
