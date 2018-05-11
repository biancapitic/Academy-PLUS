/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:43:38 by schis             #+#    #+#             */
/*   Updated: 2017/12/05 15:33:40 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	z;
	unsigned int	i;

	str = (unsigned char*)s;
	z = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == z)
			return (str + i);
		i++;
	}
	return (NULL);
}
