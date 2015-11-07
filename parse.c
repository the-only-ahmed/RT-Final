/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:57:57 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 21:08:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static int	ft_parse_verif_3(int fd, char *line, t_env *e, int i)
{
	if (!ft_parse_sphere(fd, line, e->objects, i))
		return (0);
	if (!ft_parse_cylindre(fd, line, e->objects, i))
		return (0);
	e->types[i] = ft_strdup("cone");
	return (1);
}

static int	ft_parse_verif_2(int fd, char *line, t_env *e, int i)
{
	if (!ft_parse_plan(fd, line, e->objects, i))
		return (0);
	e->types[i] = ft_strdup("plan");
	return (1);
}

int			parse_verif(char *line, int fd, t_env *e, int i)
{
	if (ft_strstr(line, "sphere"))
	{
		if (!ft_parse_sphere(fd, line, e->objects, i))
			return (0);
		e->types[i] = ft_strdup("sphere");
	}
	else if (ft_strstr(line, "cylinder"))
	{
		if (!ft_parse_sphere(fd, line, e->objects, i))
			return (0);
		if (!ft_parse_cylindre(fd, line, e->objects, i))
			return (0);
		e->types[i] = ft_strdup("cylindre");
	}
	else if (ft_strstr(line, "cone"))
		return (ft_parse_verif_3(fd, line, e, i));
	else if (ft_strstr(line, "plan"))
		return (ft_parse_verif_2(fd, line, e, i));
	else
		return (0);
	return (1);
}

static int	ft_parse_2(t_env *e, char *file)
{
	char	*line;
	int		fd;

	line = ft_strnew(0);
	if ((fd = open(file, O_RDONLY)) == -1 || (read(fd, line, 0) == -1))
		return (-1);
	while (get_next_line(fd, &line) > 0 && (line[0] == '/' || line[0] == 0))
		;
	line = delete_spaces(line, ' ');
	if (!verif_real(line))
		return (-1);
	e->fov = ft_atoi_float(line);
	return (fd);
}

int			ft_parse(char *file, t_env *e)
{
	int		fd;
	int		obj_nb;
	int		spot_nb;
	char	*line;

	if ((fd = ft_parse_2(e, file)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0 && (line[0] == '/' || line[0] == 0))
		;
	line = delete_spaces(line, ' ');
	if (!verif_vect(line))
		return (-1);
	e->cam_ray = ft_fill_vect(line, e->cam_ray);
	if (!ft_parse_init(&obj_nb, &spot_nb, e, fd))
		return (-1);
	if (!the_parse(fd, obj_nb, spot_nb, e))
		return (-1);
	e->spot[spot_nb] = NULL;
	e->types[obj_nb] = NULL;
	e->objects[obj_nb] = NULL;
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
