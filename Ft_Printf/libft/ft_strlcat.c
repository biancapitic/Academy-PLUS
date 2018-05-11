/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:51:56 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 16:04:11 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	s;
	size_t	j;

	i = 0;
	l = 0;
	j = 0;
	s = ft_strlen((char *)src);
	while (dst[i] && size > 0)
	{
		l++;
		i++;
		size--;
	}
	while (src[j] && size > 1)
	{
		dst[i] = src[j];
		i++;
		j++;
		size--;
	}
	if (size == 1 || src[j] == '\0')
		dst[i] = '\0';
	return (s + l);
}
