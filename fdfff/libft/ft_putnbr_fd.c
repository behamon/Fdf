/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:40:44 by behamon           #+#    #+#             */
/*   Updated: 2016/11/05 12:40:48 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb > 0)
		nb *= -1;
	else if (nb == 0 || nb == -2147483648)
		nb *= -1;
	else
		ft_putchar_fd('-', fd);
	if (nb <= -10)
	{
		ft_putnbr_fd(-nb / 10, fd);
		nb = nb % 10;
	}
	ft_putchar_fd(-nb + '0', fd);
}
