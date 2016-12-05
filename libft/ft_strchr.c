/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:12:05 by behamon           #+#    #+#             */
/*   Updated: 2016/11/03 18:12:08 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	chr;
	char	*ptr;

	i = 0;
	chr = (char)c;
	ptr = (char*)str;
	while (i <= ft_strlen(str))
	{
		if (ptr[i] == chr)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
