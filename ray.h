/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 23:56:54 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:38:04 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <libft.h>
# include <mlx.h>
# include "lists.h"
# include <X11/xlib.h>
# include <fcntl.h>
# include <math.h>
# include "lists.h"

# define COMMENT (get_next_line(fd, &line) > 0 && (line[0] == '/' || !line[0]))

int			ft_parse(char *str, t_env *e);
t_vect3		*ft_vect_init(double x, double y, double z);
t_vect3		*add_vect(t_vect3 *v1, t_vect3 *v2);
t_vect3		*mult_vect(t_vect3 *v1, t_vect3 *v2);
t_vect3		*mult_vectf(t_vect3 *v, double a);
double		ft_dot(t_vect3 *v1, t_vect3 *v2);
void		ft_render(t_env *e);
double		ft_mix(double a, double b, double mix);
void		fn_normalize(t_vect3 *v);
double		fn_length2(t_vect3 *v);
double		ft_pow(double x, int p);
t_vect3		*fn_trace(t_vect3 *rayorig, t_vect3 *raydir, t_env *e, int depth);

int			ft_parse_sphere(int fd, char *line, t_sp **sphere, int i);
char		*delete_spaces(char *str, char c);
t_vect3		*sub_vect(t_vect3 *v1, t_vect3 *v2);
int			ft_parse_spot(int fd, char *line, t_sp **spot, int i);
int			ft_parse_cylindre(int fd, char *line, t_sp **sphere, int i);
int			ft_parse_plan(int fd, char *line, t_sp **plan, int i);

char		*fn_object_choose(t_vect3 *rayorig, t_vect3 *raydir, t_env *e, \
								t_vars *var);
void		effects(t_vars *var, t_env *e, int depth, t_vect3 *raydir);
t_sp		*fn_spoting(t_vect3 *rayorig, t_vect3 *raydir, t_env *e, \
							double *tnear);

void		ft_lighting(t_vars *var, t_env *e);
int			intersect_sp(t_sp *sphere, t_vect3 *rayorig, t_vect3 *raydir, \
							t_vars *v);
int			intersect_cy(t_sp *sphere, t_vect3 *rayorig, t_vect3 *raydir, \
							t_vars *v);
int			intersect_con(t_sp *cone, t_vect3 *rayorig, t_vect3 *raydir, \
							t_vars *v);
int			intersect_plan(t_sp *plan, t_vect3 *rayorig, t_vect3 *raydir, \
							double *t);

int			object_choose(t_vect3 *org, t_vect3 *dir, t_env *e, t_vars *v);
double		ft_disc(double a, double b, double c);
double		ft_dot_inf(t_vect3 *v1, t_vect3 *v2, char axe);
t_vect3		*object_point(char *str, t_vars *v, t_vect3 *rayorig, t_vect3 *dir);
t_vect3		*object_normal(char *str, t_vars *v);

int			verif_real(char *line);
int			verif_vect(char *line);
t_vect3		*ft_fill_vect(char *line, t_vect3 *v);
int			verif_obj(char *line, t_env *e, int fd, int i);
int			verif_spot(char *line, t_env *e, int fd, int i);
int			ft_parse_init(int *obj_nb, int *spot_nb, t_env *e, int fd);
int			parse_verif(char *line, int fd, t_env *e, int i);
int			the_parse(int fd, int obj_nb, int spot_nb, t_env *e);

double		ft_max(double a, double b);
double		ft_min(double a, double b);

#endif
