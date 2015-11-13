/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 20:09:25 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/12 20:26:28 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			count_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		fill_obj(int fd, t_overview *over)
{
	t_obj	*obj;
	char	*trim;
	char	*str;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->next = NULL;
	obj->specular = 0;
	while (get_next_line(fd, &str))
	{
		trim = ft_strtrim(str);
		if (object_to_fill(trim, obj) == FALSE)
			break ;
	}
	if (obj->specular)
		obj->specular = 1.0f - obj->diffuse;
	over->l = add_obj(over->l, obj);
}

void		fill_cam(t_overview *over, char *trim)
{
	char **tab;

	tab = ft_strsplit(trim, ' ');
	if (count_tab(tab) < 7)
	{
		ft_putendl("Error cam parsing");
		exit(0);
	}
	over->cam.x = ft_atof(tab[1]);
	over->cam.y = ft_atof(tab[2]);
	over->cam.w = ft_atof(tab[3]);
	over->dir.x = ft_atof(tab[4]);
	over->dir.y = ft_atof(tab[5]);
	over->dir.w = ft_atof(tab[6]);
}

void		parsing(int fd, t_overview *over)
{
	char *str;
	char *trim;

	while (get_next_line(fd, &str))
	{
		trim = ft_strtrim(str);
		if (!ft_strncmp("}", trim, 1))
			return ;
		if (!ft_strncmp("cam:", trim, 4))
			fill_cam(over, trim);
		else if (!ft_strncmp("obj:", trim, 4))
			fill_obj(fd, over);
	}
}

t_overview	ft_parser(char *path)
{
	int			fd;
	char		*str;
	char		*trim;
	t_overview	over;

	over.l = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Cannot open file");
		exit(0);
	}
	while (get_next_line(fd, &str))
	{
		trim = ft_strtrim(str);
		if (!ft_strncmp("{", trim, 1))
			parsing(fd, &over);
	}
	return (over);
}
