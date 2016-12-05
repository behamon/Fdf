/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:09:56 by behamon           #+#    #+#             */
/*   Updated: 2016/11/17 17:53:46 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_int_size(int nb)
{
	size_t size;

	size = 1;
	if (nb < 0)
		size++;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int		neg;
	char	*nbr;
	size_t	size;

	neg = (n < 0) ? -1 : 1;
	size = ft_int_size(n);
	if (!(nbr = ft_strnew(size)))
		return (NULL);
	if (n < 0)
		nbr[0] = '-';
	size--;
	nbr[size--] = neg * (n % 10) + '0';
	while ((n = n / 10))
		nbr[size--] = neg * (n % 10) + '0';
	return (nbr);
}
