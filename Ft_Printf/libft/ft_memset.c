/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:29:31 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/14 18:33:59 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*pb;
	unsigned char	ch;

	pb = b;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		pb[i] = ch;
		i++;
	}
	return (pb);
}
