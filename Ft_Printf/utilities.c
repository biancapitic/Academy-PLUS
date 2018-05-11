/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:09:38 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:09:44 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putnbr2(unsigned int n)
{
	unsigned int i;

	i = n;
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	if (i < 10)
		ft_putchar(i + '0');
}

int		ft_len(unsigned int nbr)
{
	int		len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int		ft_len2(unsigned long long nbr)
{
	int		len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int		prec1(int index, char *format)
{
	if (!ft_isdigit(format[index]) && format[index] != '.')
		return (0);
	while (format[index] != '%')
	{
		if (format[index] == '.')
			return (1);
		index--;
	}
	return (2);
}

char	*crop(char *str, int mx)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * (mx + 1))))
		return (NULL);
	while (i < mx)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
