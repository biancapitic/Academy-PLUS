/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:20:43 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/08 20:14:00 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_size(char const *s, char c)
{
	int		i;
	int		n;
	char	*p;

	p = (char*)s;
	i = 0;
	n = 0;
	while (p[i] == c && p[i])
		i++;
	while (p[i] != c && p[i])
	{
		n++;
		i++;
	}
	return (n);
}

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		size;
	char	*p;
	int		j;

	if (!s)
		return (0);
	p = (char*)s;
	i = 0;
	size = 0;
	while (p[i] != '\0')
	{
		j = 0;
		while (p[i + j] != c && p[i + j] != '\0')
			j++;
		if (j != 0)
		{
			size++;
			i = i + j - 1;
		}
		i++;
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**mat;
	int		n;
	int		i;
	int		k;
	int		z;

	n = ft_count_words(s, c);
	if (!s || !(mat = (char**)malloc(sizeof(char*) * n + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (i < n)
	{
		z = 0;
		if (!(*(mat + i) = ft_strnew(ft_count_size(s + k, c))))
			return (NULL);
		while (s[k] == c && s[k] != '\0')
			k++;
		while (s[k] != c && s[k] != '\0')
			mat[i][z++] = s[k++];
		mat[i][z] = '\0';
		i++;
	}
	mat[i] = 0;
	return (mat);
}
