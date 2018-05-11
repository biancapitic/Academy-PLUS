/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:22:39 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/01 19:10:45 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (p1[i] == p2[i] && (p1[i] != '\0' && p2[i] != '\0'))
		i++;
	if (p1[i] > p2[i])
		return (p1[i] - p2[i]);
	else if (p2[i] > p1[i])
		return (p1[i] - p2[i]);
	else
		return (0);
}
