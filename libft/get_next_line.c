/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 10:19:40 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:55:18 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libft.h>

t_ahmed		*files(int fd, t_ahmed *tmp)
{
	if (tmp == NULL)
	{
		tmp = malloc(sizeof(t_ahmed));
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = NULL;
	}
	else
	{
		while (tmp != NULL && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(t_ahmed));
			tmp->fd = fd;
			tmp->str = NULL;
			tmp->next = NULL;
		}
	}
	return (tmp);
}

int			buffering(int ret, t_ahmed *tmp, char **line, char *buff)
{
	if (tmp->str != NULL)
	{
		*line = ft_strjoin(*line, tmp->str);
		tmp->str = NULL;
	}
	if (ft_strchr(buff, '\n') || ret < BUFF_SIZE)
	{
		tmp->str = ft_strchr(buff, '\n') + 1;
		*line = ft_strjoin(*line, ft_strsub(buff, 0, (tmp->str - 1) - buff));
		return (1);
	}
	else
	{
		if (tmp->str != NULL)
		{
			buff = ft_strjoin(buff, tmp->str);
			buff = NULL;
		}
		*line = ft_strjoin(*line, buff);
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	int				ret;
	static char		*buff = NULL;
	static t_ahmed	*eng = NULL;

	if (fd == -1 || (ret = read(fd, buff, 0)) == -1)
		return (-1);
	*line = ft_strnew(0);
	eng = files(fd, eng);
	if (fn_buffer(eng, line))
		return (1);
	buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (buffering(ret, eng, line, buff))
			return (1);
	}
	free(buff);
	return (0);
}

int			fn_buffer(t_ahmed *tmp, char **line)
{
	char	*p;

	if (tmp->str != NULL && (p = ft_strchr(tmp->str, '\n')))
	{
		*line = ft_strjoin(*line, ft_strsub(tmp->str, 0, p - tmp->str));
		tmp->str = p + 1;
		return (1);
	}
	return (0);
}
