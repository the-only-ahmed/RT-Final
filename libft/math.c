/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 02:33:25 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 20:01:27 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ahmed.h"

double			poweroften(int num)
{
	double		rst;
	int			i;

	i = 0;
	rst = 1;
	if (num >= 0)
	{
		while (i < num)
		{
			rst *= 10;
			i++;
		}
	}
	else
	{
		while (i < (0 - num))
		{
			rst *= 0.1;
			i++;
		}
	}
	return (rst);
}

double			square(double a)
{
	double		rst;
	int			i;
	double		j;

	rst = 0;
	j = 1;
	i = 8;
	while (i > 0)
	{
		if (a - ((2 * rst) + (j * poweroften(i))) * (j * poweroften(i)) >= 0)
		{
			while ((a - ((2 * rst) + (j * poweroften(i))) *
				(j * poweroften(i)) >= 0) && (j < 10))
				j++;
			j--;
			a -= ((2 * rst) + (j * poweroften(i))) * (j * poweroften(i));
			rst += j * poweroften(i);
			j = 1.0;
		}
		i--;
	}
	return (square_suite(rst, j, a));
}

double			square_suite(double rst, double j, double a)
{
	int		i;

	i = 0;
	while (i >= -8)
	{
		if (a - ((2 * rst) + (j * poweroften(i))) * (j * poweroften(i)) >= 0)
		{
			while (a - ((2 * rst) + (j * poweroften(i))) *
				(j * poweroften(i)) >= 0)
				j++;
			j--;
			a -= ((2 * rst) + (j * poweroften(i))) * (j * poweroften(i));
			rst += j * poweroften(i);
			j = 1.0;
		}
		i--;
	}
	return (rst);
}
