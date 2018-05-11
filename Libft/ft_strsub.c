/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:45 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 20:16:23 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ps;
	char			*str;
	unsigned int	j;

	if (!s)
		return (NULL);
	ps = (char*)s;
	j = 0;
	while (ps[j] != '\0')
		j++;
	if (len + start > ft_strlen(s) || len > j)
		return (NULL);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = ps[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}
