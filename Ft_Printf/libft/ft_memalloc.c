/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:50:41 by bpitic            #+#    #+#             */
/*   Updated: 2017/11/29 15:13:44 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	if (size == 0)
		return (NULL);
	p = malloc(sizeof(size_t) * size);
	if (p == 0)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
