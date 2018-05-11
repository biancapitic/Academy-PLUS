/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:00:03 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 20:08:15 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (pdst <= psrc || ((psrc + len) <= pdst))
		while (len)
		{
			*pdst++ = *psrc++;
			len--;
		}
	else
	{
		pdst = pdst + len - 1;
		psrc = psrc + len - 1;
		while (len--)
			*pdst-- = *psrc--;
	}
	return (dst);
}
