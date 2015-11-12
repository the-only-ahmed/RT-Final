/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 20:07:42 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/12 20:25:57 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		sub_vec(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.w = a.w - b.w;
	return (ret);
}

t_vec		sub_value(t_vec a, double b)
{
	t_vec ret;

	ret.x = a.x - b;
	ret.y = a.y - b;
	ret.w = a.w - b;
	return (ret);
}

t_vec		add_value(t_vec a, double b)
{
	t_vec ret;

	ret.x = a.x + b;
	ret.y = a.y + b;
	ret.w = a.w + b;
	return (ret);
}

t_vec		mul_vec(t_vec a, double b)
{
	t_vec ret;

	ret.x = a.x * b;
	ret.y = a.y * b;
	ret.w = a.w * b;
	return (ret);
}

t_vec		add_vec(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.w = a.w + b.w;
	return (ret);
}

t_vec		multi_vec(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.w = a.w * b.w;
	return (ret);
}

t_vec		norm(t_vec a)
{
	double l;

	l = 1 / sqrtf(a.x * a.x + a.y * a.y + a.w * a.w);
	a.x *= l;
	a.y *= l;
	a.w *= l;
	return (a);
}

double		ft_dotw(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

double		ft_doty(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.w * v2.w);
}

double		ft_dotx(t_vec v1, t_vec v2)
{
	return (v1.w * v2.w + v1.y * v2.y);
}
