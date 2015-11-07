/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 22:33:37 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:37:02 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_sp	*fn_spoting(t_vect3 *rayorig, t_vect3 *raydir, t_env *e, double *tnear)
{
	int			i;
	t_vars		var;
	t_sp		*spot;

	*tnear = INFINITY;
	i = 0;
	spot = NULL;
	while (e->spot[i])
	{
		var.t0 = INFINITY;
		var.t1 = INFINITY;
		if (intersect_sp(e->spot[i], rayorig, raydir, &var))
		{
			if (var.t0 < 0)
				var.t0 = var.t1;
			if (var.t0 < *tnear)
			{
				*tnear = var.t0;
				spot = e->spot[i];
			}
		}
		i++;
	}
	return (spot);
}

void	ft_lighting_2(t_vars *var, t_env *e, int j)
{
	var->transmission = ft_vect_init(1.0, 1.0, 1.0);
	var->lightdirection = sub_vect(e->spot[j]->center, var->phit);
	fn_normalize(var->lightdirection);
	var->i = 0;
}

void	ft_lighting(t_vars *var, t_env *e)
{
	int		j;

	j = 0;
	while (e->spot[j])
	{
		ft_lighting_2(var, e, j);
		while (e->objects[var->i])
		{
			if (object_choose(add_vect(var->phit, mult_vectf(var->nhit, \
					var->bias)), var->lightdirection, e, var))
			{
				var->transmission = ft_vect_init(0, 0, 0);
				break ;
			}
			var->i++;
		}
		var->surface = (add_vect(var->surface, mult_vect(mult_vectf \
			(mult_vect(var->sphere->surface_c, var->transmission), \
			ft_max(((double)(0)), ft_dot(var->nhit, var->lightdirection))), \
			e->spot[j]->emission_c)));
		free(var->lightdirection);
		free(var->transmission);
		j++;
	}
}
