/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:24:36 by bpitic            #+#    #+#             */
/*   Updated: 2017/11/30 12:58:48 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ps1;
	char	*ps2;

	i = 0;
	ps1 = (char *)s1;
	ps2 = (char *)s2;
	if (ps2[0] == '\0')
		return (ps1);
	while (i < len && ps1[i] != '\0')
	{
		j = 0;
		while (ps1[i + j] == ps2[j] && i + j < len)
		{
			if (ps2[j + 1] == '\0')
				return (ps1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
