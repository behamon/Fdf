/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:11:19 by behamon           #+#    #+#             */
/*   Updated: 2016/11/06 17:59:28 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	const unsigned char	*stmp;

	tmp = (unsigned char*)dst;
	stmp = (unsigned char*)src;
	if (dst > src)
	{
		tmp = tmp + len;
		stmp = stmp + len;
		while (len--)
			*--tmp = *--stmp;
	}
	else
		while (len--)
			*tmp++ = *stmp++;
	return (dst);
}
