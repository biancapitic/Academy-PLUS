/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:09:37 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 20:58:44 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		white_spaces(char const *s, int i)
{
	if (i == 0)
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
	else
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = white_spaces(s, 0);
	j = ft_strlen(s) - 1;
	k = 0;
	if (i == j + 1)
		str = ft_strnew(0);
	else
	{
		j = white_spaces(s, j);
		str = ft_strnew(j - i + 1);
		if (!str)
			return (NULL);
		while (i <= j)
			str[k++] = s[i++];
	}
	str[k] = '\0';
	return (str);
}
