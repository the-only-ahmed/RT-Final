/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 17:51:20 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 18:13:03 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			setparams(t_rayparams *prms, t_overview over, t_render rdr)
{
	prms->over = over;
	prms->dir = rdr.dir;
	prms->o = rdr.o;
	prms->depth = 1;
	prms->r_index = 1.0f;
	prms->distance = &(rdr.d);
}

static t_render		set_render(t_vec cam)
{
	t_render rdr;

	rdr.m_wx1 = -4;
	rdr.m_wx2 = 4;
	rdr.m_wy1 = 3;
	rdr.m_wy2 = -3;
	rdr.m_sy = 3;
	rdr.m_dx = (rdr.m_wx2 - rdr.m_wx1) / IMG_H;
	rdr.m_dy = (rdr.m_wy2 - rdr.m_wy1) / IMG_W;
	rdr.x = 0;
	rdr.y = 0;
	rdr.o = set_vec(cam.x, cam.y, cam.w);
	return (rdr);
}

static t_render		set_render_col(t_render rdr, t_rayparams *params)
{
	rdr.col = raytracer(params);
	rdr.r = (int)(rdr.col.x * 256);
	rdr.g = (int)(rdr.col.y * 256);
	rdr.b = (int)(rdr.col.w * 256);
	if (rdr.r > 255)
		rdr.r = 255;
	if (rdr.g > 255)
		rdr.g = 255;
	if (rdr.b > 255)
		rdr.b = 255;
	return (rdr);
}

void				render(t_data *data, t_overview over)
{
	t_render		rdr;
	t_rayparams		*params;

	rdr = set_render(over.cam);
	params = (t_rayparams*)malloc(sizeof(t_rayparams));
	while (rdr.y < IMG_W)
	{
		rdr.m_sx = rdr.m_wx1;
		rdr.x = 0;
		while (rdr.x < IMG_H)
		{
			rdr.dir.x = rdr.m_sx;
			rdr.dir.y = rdr.m_sy;
			rdr.dir.w = 0;
			rdr.dir = sub_vec(rdr.dir, rdr.o);
			rdr.dir = norm(rdr.dir);
			setparams(params, over, rdr);
			rdr = set_render_col(rdr, params);
			image_pixel_put(data, rdr.x, rdr.y, creatergb(rdr.r, rdr.g, rdr.b));
			rdr.x++;
			rdr.m_sx += rdr.m_dx;
		}
		rdr.m_sy += rdr.m_dy;
		rdr.y++;
	}
}
