/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:23:11 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:37:31 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

double		ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double		ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
