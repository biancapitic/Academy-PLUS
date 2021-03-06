/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:22:09 by schis             #+#    #+#             */
/*   Updated: 2017/12/09 19:18:21 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ft_abs(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int			ft_len(long int nbr)
{
	int		len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int nbr)
{
	int			len;
	int			sign;
	char		*c;

	if (nbr < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_len(nbr);
	if (!(c = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(nbr % 10);
		nbr = ft_abs(nbr / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
