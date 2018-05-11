/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:04:51 by schis             #+#    #+#             */
/*   Updated: 2017/11/26 14:33:19 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned int	i;

	i = 0;
	s = (unsigned char*)str;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
