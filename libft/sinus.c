/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 19:21:08 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 20:04:09 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ahmed.h"

double	deg_rad(int x)
{
	double	rad;

	if (x == 0)
		return (0);
	rad = (x * (PI / 180));
	return (rad);
}

double	sinus(int n)
{
	double	res;
	double	x;

	x = deg_rad(n);
	if (x < 0)
	{
		res = 1.27323954 * x + .405284735 * x * x;
		if (res < 0)
			res = .225 * (res * -res - res) + res;
		else
			res = .225 * (res * res - res) + res;
	}
	else
	{
		res = 1.27323954 * x - 0.405284735 * x * x;
		if (res < 0)
			res = .225 * (res * -res - res) + res;
		else
			res = .225 * (res * res - res) + res;
	}
	return (res);
}

double	cosinus(int n)
{
	double	res;
	double	x;

	x = deg_rad(n);
	x += 1.57079632;
	if (x > 3.14159265)
		x -= 6.28318531;
	if (x < 0)
	{
		res = 1.27323954 * x + 0.405284735 * x * x;
		if (res < 0)
			res = .225 * (res * -res - res) + res;
		else
			res = .225 * (res * res - res) + res;
	}
	else
	{
		res = 1.27323954 * x - 0.405284735 * x * x;
		if (res < 0)
			res = .225 * (res * -res - res) + res;
		else
			res = .225 * (res * res - res) + res;
	}
	return (res);
}

double	tangente(int n)
{
	double	res;
	double	x;

	x = deg_rad(n);
	res = sinus(x) / cosinus(x);
	return (res);
}

double	cotangente(int n)
{
	double	res;

	res = 1 / tangente(n);
	return (res);
}
