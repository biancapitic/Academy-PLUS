/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:14:53 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/01 14:36:46 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*p1;
	char	*p2;

	p1 = (char*)big;
	p2 = (char*)little;
	if (p2[0] == '\0')
		return (p1);
	i = 0;
	while (p1[i] != '\0')
	{
		j = 0;
		while (p1[i + j] == p2[j])
		{
			if (p2[j + 1] == '\0')
				return (p1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
