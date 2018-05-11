/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:11 by bpitic            #+#    #+#             */
/*   Updated: 2018/01/25 14:29:33 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_from_file(t_nline *nline)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	if (!(nline->str))
		nline->str = ft_strnew(0);
	while ((ret = read(nline->file, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(nline->str, buff);
		ft_strdel(&(nline->str));
		nline->str = temp;
		if (ft_strrchr(buff, '\n'))
		{
			return (1);
		}
	}
	if (ret == 0 && nline->str[0])
		return (1);
	return (ret);
}

void	split(t_nline *nline, char **line)
{
	char	*catel;
	char	*pisica;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nline->str[i] && nline->str[i] != '\n')
		i++;
	if (!(catel = ft_strnew(i)))
		return ;
	ft_strncpy(catel, nline->str, i);
	if (nline->str[i] == '\n')
		i++;
	if (!(pisica = ft_strnew(ft_strlen(nline->str) - i)))
		return ;
	while (nline->str[i + j])
	{
		pisica[j] = nline->str[i + j];
		j++;
	}
	*line = catel;
	ft_strdel(&nline->str);
	nline->str = pisica;
}

t_nline	*list(t_nline **lst, int fd)
{
	t_nline *temp;
	t_nline *prev;

	if (fd < 0)
		return (NULL);
	temp = *lst;
	prev = NULL;
	while (temp != NULL)
	{
		if (temp->file == fd)
			return (temp);
		prev = temp;
		temp = temp->next;
	}
	if (!(temp = (t_nline*)malloc(sizeof(t_nline))))
		return (NULL);
	temp->file = fd;
	temp->next = NULL;
	temp->str = NULL;
	if (prev == NULL)
		*lst = temp;
	else
		prev->next = temp;
	return (temp);
}

int		get_next_line(int const fd, char **line)
{
	static t_nline	*nline;
	t_nline			*temp;
	int				ret;

	if (!line)
		return (-1);
	temp = list(&nline, fd);
	if (temp == NULL)
		return (-1);
	if ((ret = read_from_file(temp)) > 0)
	{
		split(temp, line);
	}
	return (ret);
}
