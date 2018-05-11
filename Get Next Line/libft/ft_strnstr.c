/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:59:47 by schis             #+#    #+#             */
/*   Updated: 2017/12/09 19:27:32 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char			*s1;
	char			*s2;

	s1 = (char *)big;
	s2 = (char *)little;
	if (!*little)
		return (s1);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < n)
		{
			if (s2[j + 1] == '\0')
				return (s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
