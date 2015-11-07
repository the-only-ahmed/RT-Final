/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 20:40:46 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/21 19:07:30 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

double		ft_disc(double a, double b, double c)
{
	double		delta;

	delta = ft_pow(b, 2) - (4 * a * c);
	return (delta);
}

double		ft_dot_inf(t_vect3 *v1, t_vect3 *v2, char axe)
{
	double		dot;

	if (axe == 'x')
		dot = v1->y * v2->y + v1->z * v2->z;
	else if (axe == 'y')
		dot = v1->x * v2->x + v1->z * v2->z;
	else if (axe == 'z')
		dot = v1->x * v2->x + v1->y * v2->y;
	else
	{
		ft_printf("ERROR !\n");
		exit(0);
	}
	return (dot);
}
