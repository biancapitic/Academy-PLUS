/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:39:25 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/01 20:34:33 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	p = (char *)src;
	while (dest[i] != '\0')
		i++;
	while (j < n && p[j] != '\0')
	{
		dest[i] = p[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
