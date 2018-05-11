/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 12:22:55 by schis             #+#    #+#             */
/*   Updated: 2017/12/01 13:50:26 by schis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_sign(char c, int *sign, int *i)
{
	if (c == '-')
	{
		*sign = -1;
		*i = *i + 1;
	}
	if (c == '+')
		*i = *i + 1;
}

static int		spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int i;
	int nr;
	int sign;

	sign = 1;
	i = 0;
	nr = 0;
	while (spaces(str[i]) == 1)
		i++;
	if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		return (0);
	get_sign(str[i], &sign, &i);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (sign * nr);
		nr = nr * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nr);
}
