/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 20:04:33 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/12 20:04:46 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned long		creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void				image_pixel_put(t_data *e, int x, int y, int color)
{
	int addr;

	addr = (e->bpp >> 3) * ((y * (e->sl >> 2)) + x);
	memcpy(e->str + addr, &color, 4);
}
