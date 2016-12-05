/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:27:23 by behamon           #+#    #+#             */
/*   Updated: 2016/11/07 16:44:31 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *alst;
	if (alst)
	{
		while (ptr != NULL)
		{
			next = ptr->next;
			ft_lstdelone(&ptr, del);
			ptr = next;
		}
		*alst = NULL;
	}
}
