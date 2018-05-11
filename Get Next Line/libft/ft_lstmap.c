/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:05:20 by schis             #+#    #+#             */
/*   Updated: 2017/12/07 16:38:39 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *new;
	t_list *ret;

	if (!lst)
		return (NULL);
	list = f(lst);
	if (!(new = ft_lstnew(list->content, list->content_size)))
		return (NULL);
	lst = lst->next;
	ret = new;
	while (lst)
	{
		list = f(lst);
		if (!(new->next = ft_lstnew(list->content, list->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (ret);
}
