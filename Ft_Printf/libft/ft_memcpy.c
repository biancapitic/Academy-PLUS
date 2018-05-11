/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:33:22 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/02 12:06:29 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;
	size_t	i;

	pdst = (char *)dst;
	if (n)
	{
		i = 0;
		psrc = (char *)src;
		while (i < n)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (pdst);
}
