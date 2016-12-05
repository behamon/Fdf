/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:55:04 by behamon           #+#    #+#             */
/*   Updated: 2016/11/07 21:16:26 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmp;
	const unsigned char	*stmp;

	i = 0;
	tmp = (unsigned char*)dst;
	stmp = (unsigned char*)src;
	while (i < n)
	{
		tmp[i] = stmp[i];
		if (stmp[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
