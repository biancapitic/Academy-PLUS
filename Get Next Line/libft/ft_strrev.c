/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:45:17 by schis             #+#    #+#             */
/*   Updated: 2017/12/09 20:06:33 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	aux;

	if (str == NULL)
		return (NULL);
	j = 0;
	i = ft_strlen(str) - 1;
	while (j < i)
	{
		aux = str[j];
		str[j] = str[i];
		str[i] = aux;
		j++;
		i--;
	}
	return (str);
}
