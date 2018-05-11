/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:08:39 by schis             #+#    #+#             */
/*   Updated: 2017/11/26 15:18:20 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	if (size == 0)
		return (NULL);
	p = malloc(sizeof(*p) * size);
	if (p == 0)
		return (NULL);
	ft_memset(p, '\0', size);
	return (p);
}
