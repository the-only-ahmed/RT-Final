/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 17:53:19 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 19:11:15 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

typedef int			t_bool;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			w;
}					t_vec;

typedef struct		s_obj
{
	char			*name;
	t_vec			pos;
	t_vec			col;
	t_bool			light;
	double			diffuse;
	double			specular;
	double			reflection;
	double			radius;
	int				type;
	char			axe;
	struct s_obj	*next;
	double			refraction;
	double			index_refraction;
}					t_obj;

typedef struct		s_overview
{
	t_obj			*l;
	t_vec			cam;
	t_vec			dir;
}					t_overview;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*str;
	int				bpp;
	int				sl;
	int				nd;
}					t_data;

typedef struct		s_plane
{
	int				w;
	int				h;
	t_vec			upleft;
	double			incx;
	double			incy;
}					t_plane;

typedef struct		s_raytracer
{
	t_obj			*tmp;
	t_obj			*ret;
	t_vec			l;
	t_vec			n;
	t_vec			r;
	t_vec			pi;
	t_vec			color;
	double			i;
	double			mag;
	double			ret2;
	double			dot;
	double			shade;
	int				result;
	int				result2;
	int				hit;
	int				hit2;
	int				in;
}					t_raytracer;

typedef struct		s_rayprams
{
	t_overview		over;
	t_vec			dir;
	t_vec			o;
	int				depth;
	int				*distance;
	double			r_index;
}					t_rayparams;

typedef struct		s_refraction
{
	t_vec			t_ref;
	t_vec			t_ref3;
	t_vec			col_ref;
	t_vec			n_ref;
	double			n_r;
	double			cos_i;
	double			cos_t2;
	double			t_ref2;
}					t_refraction;

typedef struct		s_specular
{
	t_vec			v_spec;
	t_vec			r_spec;
	t_vec			ret_spec;
	double			r_spect;
	double			dot_spec;
	double			spect_diff;
}					t_specular;

typedef struct		s_render
{
	double			m_wx1;
	double			m_wx2;
	double			m_wy1;
	double			m_wy2;
	double			m_sy;
	double			m_dx;
	double			m_dy;
	double			m_sx;
	int				x;
	int				y;
	int				d;
	int				r;
	int				g;
	int				b;
	t_vec			viewplane;
	t_vec			o;
	t_vec			dir;
	t_vec			col;
}					t_render;

typedef struct		s_cylinder
{
	double			a;
	double			b;
	double			c;
	double			delt;
	double			a1;
	double			b1;
	double			ret;
}					t_cylinder;

#endif
