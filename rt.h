/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 18:57:57 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/19 21:55:20 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <fcntl.h>
# include <math.h>
# include <dirent.h>
# include <libft.h>
# include "mlx.h"
# include "lists.h"
# include "time.h"

# define TRUE 1
# define FALSE 0
# define IMG_H 1600
# define IMG_W 1400
# define PI			3.14159265359
# define FOV			(double)30
# define FOV2			FOV / 2
# define SCR_DIST		(p->window.w / 2) / tan(FOV2)
# define DEGTORAD(A)	((A) / 180.0 * PI)
# define DOT(A,B)		(A.x*B.x+A.y*B.y+A.w*B.w)
# define NL(V) {float l=1/sqrtf(A.x*A.x+A.y*A.y+A.w*A.w);A.x*=l;A.y*=l;A.w*=l;}
# define MAG(VA) ((sqrt(VA.x * VA.x + VA.y * VA.y + VA.w * VA.w)))
# define SPHERE 0
# define PLAN 1
# define CYLINDRE 2
# define CONE 3
# define EPSILON 0.0001f
# define MAX_DEPTH 6
# define UP 126
# define DOWN 125
# define ENTER 36
# define ESC 53
# define LENGTH(A)		(sqrtf(A.x*A.x+A.y*A.y+A.w*A.w))

int				ft_key_hook(int key_code, t_data *e);
int				menu_hook(t_data *e);
int				quality_hook(t_data *e);
t_files			*set_quality();
void			printselected(t_data *e, int q);
int				ft_expose_hook(t_data *e);
void			render(t_data *data, t_overview over);
t_bool			object_to_fill(char *trim, t_obj *obj);
void			return_i(t_raytracer *ray, t_vec dir, t_vec o);
t_vec			set_nvec(t_obj *ret, t_vec dir, t_vec o, double ret2);
t_vec			set_vec(double x, double y, double z);
t_vec			init_vec(void);
t_raytracer		*init_ray(t_obj *l);
void			refraction(t_raytracer *ray, t_rayparams *params);
void			reflexion(t_raytracer *ray, t_rayparams *params);
t_vec			depth_inf_maxdepth(t_raytracer *r, t_rayparams *p, double re);
void			tmp_type_sphere(t_raytracer *ray, t_obj *l);
void			first_loop(t_raytracer *ray, t_vec dir, t_vec o);
t_vec			dot_positif(t_raytracer *ray);
double			hit_sphere(t_vec dir, t_vec o, t_obj *obj);
double			hit_plane(t_vec dir, t_vec o, t_obj *obj);
double			hit_cyl(t_vec dir, t_vec o, t_obj *obj);
int				ft_intercone(t_vec rayorg, t_vec raydir, t_obj *obj);
t_vec			raytracer(t_rayparams *params);
t_overview		ft_parser(char *path);
double			ft_atof(char *str);
void			fill_name(char *s, t_obj *o);
void			fill_diff(char *s, t_obj *o);
void			fill_reflection(char *s, t_obj *o);
void			fill_color(char *s, t_obj *o);
void			fill_pos(char *s, t_obj *o);
void			fill_light(char *s, t_obj *o);
int				count_tab(char **tab);
t_obj			*add_obj(t_obj *l, t_obj *to_add);
double			ft_pow(double x, double y);
t_vec			sub_vec(t_vec a, t_vec b);
t_vec			mul_vec(t_vec a, double b);
t_vec			add_vec(t_vec a, t_vec b);
t_vec			multi_vec(t_vec a, t_vec b);
t_vec			norm(t_vec a);
t_vec			sub_value(t_vec a, double b);
t_vec			add_value(t_vec a, double b);
unsigned long	creatergb(int r, int g, int b);
void			image_pixel_put(t_data *e, int x, int y, int color);
void			fill_spe(char *s, t_obj *obj);
void			fill_refra(char *s, t_obj *obj);
double			ft_dotw(t_vec v1, t_vec v2);
double			ft_doty(t_vec v1, t_vec v2);
double			ft_dotx(t_vec v1, t_vec v2);
void			fill_axe(char *s, t_obj *obj);
void			fill_specular(char *s, t_obj *obj);

#endif
