/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:35:28 by bpitic            #+#    #+#             */
/*   Updated: 2018/01/25 14:35:31 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 543
# include "libft/libft.h"
# include <fcntl.h>

typedef	struct		s_nline
{
	char			*str;
	int				file;
	struct s_nline	*next;
}					t_nline;

int					get_next_line(int const fd, char **line);

#endif
