/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:10:21 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:10:27 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_len3(uintmax_t nbr)
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

char	*ft_itoa3(uintmax_t nbr)
{
	int			len;
	char		*c;

	len = ft_len3(nbr);
	if (!(c = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nbr == 0)
	{
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + nbr % 10;
		nbr = nbr / 10;
		len--;
	}
	return (c);
}

char	*ft_itoa2(unsigned long long nbr)
{
	int			len;
	char		*c;

	len = ft_len2(nbr);
	if (!(c = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nbr == 0)
	{
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + nbr % 10;
		nbr = nbr / 10;
		len--;
	}
	return (c);
}

char	*convert6(int num, int base)
{
	static char representation[] = "0123456789abcdef";
	static char buffer[50];
	char		*ptr;
	int			nr;

	nr = (unsigned char)num;
	ptr = &buffer[49];
	*ptr = '\0';
	if (nr == 0)
		return ("0");
	while (nr != 0)
	{
		*--ptr = representation[nr % base];
		nr /= base;
	}
	return (ptr);
}

void	chestie(char *s, t_vars *z)
{
	z->nr = z->mn - ft_strlen(s);
	while (z->nr > 0)
	{
		ft_putchar(' ');
		z->ret++;
		z->nr--;
	}
}
