/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 18:50:01 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 19:19:21 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	object_to_fill(char *trim, t_obj *obj)
{
	if (!ft_strncmp("name:", trim, 4))
		fill_name(trim, obj);
	else if (!ft_strncmp("diff:", trim, 5))
		fill_diff(trim, obj);
	else if (!ft_strncmp("ref:", trim, 4))
		fill_reflection(trim, obj);
	else if (!ft_strncmp("color:", trim, 6))
		fill_color(trim, obj);
	else if (!ft_strncmp("refraction:", trim, 11))
		fill_refra(trim, obj);
	else if (!ft_strncmp("specular:", trim, 9))
		fill_specular(trim, obj);
	else if (!ft_strncmp("light:", trim, 6))
		fill_light(trim, obj);
	else if (!ft_strncmp("pos:", trim, 4))
		fill_pos(trim, obj);
	else if (!ft_strncmp("axe:", trim, 4))
		fill_axe(trim, obj);
	else if (!ft_strncmp("}", trim, 1))
		return (FALSE);
	return (TRUE);
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
