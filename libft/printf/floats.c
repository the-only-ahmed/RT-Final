/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 00:31:24 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:56:17 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libftprintf.h"

static int		ft_atoi_float2(char *str, double *x, int *neg, int *pt)
{
	int		i;

	i = 0;
	*x = 0;
	*pt = 0;
	*neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && str[i - 1] != '+')
	{
		*neg = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		*x *= 10;
		*x += str[i] - 48;
		i++;
	}
	return (i);
}

double			ft_atoi_float(const char *str)
{
	int			i;
	double		x;
	int			pt;
	double		a;
	int			neg;

	i = ft_atoi_float2((char*)str, &x, &neg, &pt);
	a = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
		{
			a *= 10;
			a += str[i++] - 48;
			pt++;
		}
	}
	while (pt > 0)
	{
		a = a / 10;
		pt--;
	}
	x = (x + a) * neg;
	return (x);
}
