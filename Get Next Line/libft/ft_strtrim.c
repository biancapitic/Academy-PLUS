/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:47:53 by schis             #+#    #+#             */
/*   Updated: 2017/12/09 19:57:26 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*str;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		l--;
	if (l <= 0)
		l = 0;
	str = (char*)malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < l)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
