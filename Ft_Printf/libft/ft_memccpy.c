/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:15:19 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 19:36:54 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*pdst;
	unsigned char			*psrc;
	unsigned char			ch;
	size_t					i;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == ch)
			return (pdst + i + 1);
		i++;
	}
	return (0);
}
