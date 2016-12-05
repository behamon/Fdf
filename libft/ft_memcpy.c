/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:22:32 by behamon           #+#    #+#             */
/*   Updated: 2016/11/07 11:17:24 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
