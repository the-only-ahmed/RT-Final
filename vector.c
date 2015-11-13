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
