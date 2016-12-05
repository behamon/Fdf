/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:04:44 by behamon           #+#    #+#             */
/*   Updated: 2016/11/08 20:28:30 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*ptr;
	t_list	*last;

	if (!lst || !f)
		return (NULL);
	ptr = f(lst);
	newlist = ft_lstnew(ptr->content, ptr->content_size);
	last = newlist;
	lst = lst->next;
	while (lst)
	{
		ptr = f(lst);
		last->next = ft_lstnew(ptr->content, ptr->content_size);
		last = last->next;
		lst = lst->next;
	}
	return (newlist);
}
