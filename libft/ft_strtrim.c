/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:52:24 by behamon           #+#    #+#             */
/*   Updated: 2016/11/05 14:21:05 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strtrim_len(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = i;
	while (s[len + 1])
		len++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	return (len - i + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (s)
	{
		len = ft_strtrim_len(s);
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (j < len)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	return (0);
}
