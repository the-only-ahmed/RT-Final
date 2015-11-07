/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:47:35 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:25:10 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vect3		*ft_fill_vect(char *line, t_vect3 *v)
{
	char		**tab;
	double		*tmp;

	tab = ft_strsplit(line, ',');
	tmp = (double*)malloc(sizeof(double) * 3);
	tmp[0] = ft_atoi_float(&tab[0][1]);
	tmp[1] = ft_atoi_float(tab[1]);
	tmp[2] = ft_atoi_float(tab[2]);
	v = ft_vect_init(tmp[0], tmp[1], tmp[2]);
	free(tab);
	free(tmp);
	return (v);
}

int			verif_obj(char *line, t_env *e, int fd, int i)
{
	if (ft_occ_nb(line, '*') != 1 && line[0] != '*')
		return (0);
	if (!parse_verif(line, fd, e, i))
		return (0);
	return (1);
}

int			verif_spot(char *line, t_env *e, int fd, int i)
{
	if (ft_occ_nb(line, '*') != 1 && line[0] != '*')
		return (0);
	if (ft_strstr(line, "spot"))
		ft_parse_spot(fd, line, e->spot, i);
	else
		return (0);
	return (1);
}

int			verif_number(char *line)
{
	int		i;

	if (ft_occ_nb(line, '#') != 1 && line[0] != '#' && ft_occ_nb(line, ' ') > 1)
		return (-1);
	i = 1;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
		{
			if (line[i] != ' ')
				return (-1);
			else if (line[i] == ' ' && i != 1)
				return (-1);
		}
		i++;
	}
	return (ft_atoi(&line[1]));
}

int			ft_parse_init(int *obj_nb, int *spot_nb, t_env *e, int fd)
{
	char	*line;

	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if ((*obj_nb = verif_number(line)) < 0)
		return (0);
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if ((*spot_nb = verif_number(line)) < 0)
		return (0);
	if ((e->objects = (t_sp**)malloc(sizeof(t_sp*) * (*obj_nb + 1))) == NULL)
		return (0);
	if ((e->types = (char**)malloc(sizeof(char*) * (*obj_nb + 1))) == NULL)
		return (0);
	if ((e->spot = (t_sp**)malloc(sizeof(t_sp*) * (*spot_nb + 1))) == NULL)
		return (0);
	return (1);
}
