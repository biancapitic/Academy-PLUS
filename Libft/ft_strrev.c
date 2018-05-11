/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 22:08:07 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/09 20:08:41 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	aux;

	if (!str)
		return (NULL);
	i = ft_strlen(str) - 1;
	j = 0;
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
