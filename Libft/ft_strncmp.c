/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 17:34:39 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/14 19:17:06 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (i < n && (p1[i] != '\0' || p2[i] != '\0'))
	{
		if (p1[i] > p2[i] || p1[i] < p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
