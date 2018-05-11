/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:13:32 by schis             #+#    #+#             */
/*   Updated: 2017/12/09 19:57:49 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		words(const char *str, const char c)
{
	unsigned int i;
	unsigned int s;

	i = 0;
	s = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i])
		{
			s++;
			while (str[i] != c && str[i])
				i++;
			i--;
		}
		i++;
	}
	return (s);
}

static int				word_lenght(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		k++;
		i++;
	}
	return (k);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**mat;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s || !(mat = (char **)malloc(sizeof(char *) * words(s, c) + 1)))
		return (NULL);
	while (j < words(s, c))
	{
		k = 0;
		mat[j] = ft_strnew(word_lenght(s + i, c));
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			mat[j][k++] = s[i++];
		mat[j][k] = '\0';
		j++;
	}
	mat[j] = 0;
	return (mat);
}
