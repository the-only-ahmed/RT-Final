/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 19:35:35 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/12 19:40:45 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_name(char *s, t_obj *obj)
{
	char **tab;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 2)
	{
		ft_putendl("Parse problem diff");
		exit(0);
	}
	obj->name = ft_strdup(tab[1]);
	if (!ft_strcmp(obj->name, "sphere"))
		obj->type = SPHERE;
	else if (!ft_strcmp(obj->name, "plan"))
		obj->type = PLAN;
	else if (!ft_strcmp(obj->name, "cylindre"))
		obj->type = CYLINDRE;
	else if (!ft_strcmp(obj->name, "cone"))
		obj->type = CONE;
	else
		obj->type = 0;
}

void	fill_diff(char *s, t_obj *obj)
{
	char **tab;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 2)
	{
		ft_putendl("Parse problem diff");
		exit(0);
	}
	obj->diffuse = ft_atof(tab[1]);
}

void	fill_specular(char *s, t_obj *obj)
{
	char **tab;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 2)
	{
		ft_putendl("Parse problem diff");
		exit(0);
	}
	if (tab[1] > 0)
		obj->specular = 1;
}

void	fill_reflection(char *s, t_obj *obj)
{
	char **tab;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 2)
	{
		ft_putendl("Parse problem ref");
		exit(0);
	}
	obj->reflection = ft_atof(tab[1]);
}

void	fill_color(char *s, t_obj *obj)
{
	char **tab;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 4)
	{
		ft_putendl("Parse problem color");
		exit(0);
	}
	obj->col.x = ft_atof(tab[1]);
	obj->col.y = ft_atof(tab[2]);
	obj->col.w = ft_atof(tab[3]);
}

void	fill_refra(char *s, t_obj *obj)
{
	char **tab;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 3)
	{
		ft_putendl("Parse problem refraction");
		exit(0);
	}
	obj->refraction = ft_atof(tab[1]);
	obj->index_refraction = ft_atof(tab[2]);
}

void	fill_pos(char *s, t_obj *obj)
{
	char **tab;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 5)
	{
		ft_putendl("Parse problem pos");
		exit(0);
	}
	obj->pos.x = ft_atof(tab[1]);
	obj->pos.y = ft_atof(tab[2]);
	obj->pos.w = ft_atof(tab[3]);
	obj->radius = ft_atof(tab[4]);
}

void	fill_light(char *s, t_obj *obj)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 2)
	{
		ft_putendl("Parse problem ref");
		exit(0);
	}
	i = ft_atoi(tab[1]);
	if (i <= 0)
		obj->light = FALSE;
	else
		obj->light = TRUE;
}

void	fill_axe(char *s, t_obj *obj)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(s, ' ');
	if (count_tab(tab) < 2)
	{
		ft_putendl("Parse problem ref");
		exit(0);
	}
	obj->axe = tab[1][0];
}
