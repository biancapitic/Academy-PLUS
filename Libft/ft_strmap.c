/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:33:26 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 20:12:56 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	*ps;

	if (!s)
		return (NULL);
	i = 0;
	ps = (char *)s;
	while (ps[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (ps[i] != '\0')
	{
		str[i] = f(ps[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
