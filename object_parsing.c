/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:20:32 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:30:12 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int				ft_parse_cylindre(int fd, char *line, t_sp **sphere, int i)
{
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if (ft_occ_nb(line, '+') != 1 || line[0] != '+')
		return (0);
	line = ft_strchr(line, '+') + 1;
	if (line[0] == ' ')
		line = &line[1];
	if (ft_strlen(line) != 1 || (line[0] != 'x' && line[0] != 'y'
			&& line[0] != 'z'))
	{
		ft_printf("ERROR !\n");
		return (0);
	}
	sphere[i]->axe = line[0];
	return (1);
}

static int		fn_parse_sphere2(int fd, char *line, t_sp **sphere, int i)
{
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if (!verif_vect(line))
		return (0);
	sphere[i]->surface_c = ft_fill_vect(line, sphere[i]->surface_c);
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if (!verif_real(line))
		return (0);
	sphere[i]->reflection = ft_atoi_float(line);
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if (!verif_real(line))
		return (0);
	sphere[i]->trans = ft_atoi_float(line);
	free(line);
	return (1);
}

int				ft_parse_sphere(int fd, char *line, t_sp **sphere, int i)
{
	sphere[i] = (t_sp*)malloc(sizeof(t_sp));
	sphere[i]->emission_c = ft_vect_init(0, 0, 0);
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if (!verif_vect(line))
		return (0);
	sphere[i]->center = ft_fill_vect(line, sphere[i]->center);
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if (!verif_real(line))
		return (0);
	sphere[i]->radius = ft_atoi_float(line);
	sphere[i]->radius_2 = ft_pow(sphere[i]->radius, 2);
	if (!fn_parse_sphere2(fd, line, sphere, i))
		return (0);
	free(line);
	return (1);
}

int				ft_parse_spot(int fd, char *line, t_sp **spot, int i)
{
	if (!ft_parse_sphere(fd, line, spot, i))
		return (0);
	while (COMMENT)
		;
	line = delete_spaces(line, ' ');
	if (!verif_vect(line))
		return (0);
	spot[i]->emission_c = ft_fill_vect(line, spot[i]->emission_c);
	return (1);
}
