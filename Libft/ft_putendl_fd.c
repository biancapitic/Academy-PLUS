/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:59:05 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/14 19:24:23 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*p;
	int		i;

	if (!s)
		return ;
	p = (char*)s;
	i = 0;
	while (p[i] != '\0')
	{
		ft_putchar_fd(p[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
