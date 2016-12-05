/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:13:21 by behamon           #+#    #+#             */
/*   Updated: 2016/11/07 18:26:52 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	chr;
	char	*ptr;

	i = 0;
	chr = (char)c;
	ptr = (char*)str;
	while (ptr[i])
		i++;
	while (i)
	{
		if (ptr[i] == chr)
			return (ptr + i);
		i--;
	}
	if (ptr[i] == chr)
		return (ptr);
	return (NULL);
}
