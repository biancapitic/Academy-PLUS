/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:20:12 by schis             #+#    #+#             */
/*   Updated: 2017/12/05 15:06:34 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*sou;
	unsigned char	*dst;
	unsigned char	z;

	i = 0;
	sou = (unsigned char*)src;
	dst = (unsigned char*)dest;
	z = (unsigned char)c;
	while (i < n)
	{
		dst[i] = sou[i];
		if (dst[i] == z)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
