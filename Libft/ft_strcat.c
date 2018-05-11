/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:18:12 by bpitic            #+#    #+#             */
/*   Updated: 2017/11/30 16:19:50 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)src;
	while (dest[i] != '\0')
		i++;
	while (s[j] != '\0')
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
