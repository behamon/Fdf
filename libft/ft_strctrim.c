/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:30:25 by behamon           #+#    #+#             */
/*   Updated: 2016/11/09 11:34:56 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strtrim_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (s[i] == c)
		i++;
	len = i;
	while (s[len + 1])
		len++;
	while (s[i] == c)
		len--;
	return (len - i + 1);
}

char			*ft_strctrim(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (s)
	{
		len = ft_strtrim_len(s, c);
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[i] == c)
			i++;
		while (j < len)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	return (0);
}
