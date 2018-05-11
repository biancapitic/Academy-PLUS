/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:43:11 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 20:13:05 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ps;
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	ps = (char*)s;
	i = 0;
	while (ps[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (ps[i] != '\0')
	{
		str[i] = f(i, ps[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
