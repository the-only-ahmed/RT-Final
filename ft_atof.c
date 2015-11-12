/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 19:40:57 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/12 20:02:03 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isspace(int c)
{
	return ((c >= 0x09 && c <= 0x0D) || (c == 0x20));
}

double	ft_atof(char *s)
{
	double	val;
	double	power;
	int		sign;

	while (*s && ft_isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	val = 0.0f;
	while (*s && ft_isdigit(*s))
	{
		val = 10.0 * val + (*s - '0');
		s++;
	}
	if (*s == '.')
		s++;
	power = 1.0f;
	while (*s && ft_isdigit(*s))
	{
		val = 10.0 * val + (*s - '0');
		power *= 10.0;
		s++;
	}
	return (sign * val / power);
}
