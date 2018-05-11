/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:33:17 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 20:09:58 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;
	char	ch;

	i = 0;
	ch = (char)c;
	s = (char *)str;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	if (ch == '\0')
		return (s + i);
	return (NULL);
}
