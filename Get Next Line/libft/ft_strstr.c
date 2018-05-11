/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 10:20:45 by schis             #+#    #+#             */
/*   Updated: 2017/12/05 16:55:11 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*str1;
	char	*to_find1;

	i = 0;
	j = 0;
	str1 = (char*)str;
	to_find1 = (char*)to_find;
	if (!*to_find)
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (to_find1[j] == str1[i + j])
		{
			if (to_find1[j + 1] == '\0')
				return (str1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
