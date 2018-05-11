/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:02:51 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/14 19:29:40 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *new;
	t_list *nod;

	if (!lst)
		return (NULL);
	nod = f(lst);
	if (!(new = ft_lstnew(nod->content, nod->content_size)))
		return (NULL);
	lst = lst->next;
	head = new;
	while (lst)
	{
		nod = f(lst);
		if (!(new->next = ft_lstnew(nod->content, nod->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
