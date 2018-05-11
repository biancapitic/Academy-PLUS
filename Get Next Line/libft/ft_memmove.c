/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:56:23 by schis             #+#    #+#             */
/*   Updated: 2017/12/05 16:14:59 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (dest1 <= src1 || (dest1 + len) <= src1)
		while (len--)
			*dest1++ = *src1++;
	else
	{
		dest1 = dest1 + len - 1;
		src1 = src1 + len - 1;
		while (len--)
			*dest1-- = *src1--;
	}
	return (dest);
}
