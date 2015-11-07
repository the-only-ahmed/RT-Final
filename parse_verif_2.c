/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_verif_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:14:02 by ivannere          #+#    #+#             */
/*   Updated: 2014/03/27 19:52:08 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int			verif_real(char *line)
{
	int		i;

	if (ft_strchr(line, ' ') || ft_occ_nb(line, '.') > 1
			|| ft_occ_nb(line, '-') > 1)
		return (0);
	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
		{
			if (line[i] != '.' && line[i] != '-')
				return (0);
			else if (line[i] == '.' && (!ft_isdigit(line[i - 1])
						|| !ft_isdigit(line[i + 1])))
				return (0);
			else if (line[i] == '-' && i)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	verif_vect_2(char *line, int i)
{
	if (line[i] != '-' && line[i] != '.' && line[i] != ' '
		&& line[i] != ',')
		return (0);
	else if (line[i] == '-' && ((line[i - 1] != '{'
		&& line[i - 1] != ' ') || !ft_isdigit(line[i + 1])))
		return (0);
	else if (line[i] == '.' && (!ft_isdigit(line[i - 1])
		|| !ft_isdigit(line[i + 1])))
		return (0);
	else if (line[i] == ' ' && (line[i - 1] != ','
		|| (line[i + 1] != '-' && !ft_isdigit(line[i + 1]))))
		return (0);
	else if (line[i] == ',' && (!ft_isdigit(line[i - 1])
		|| line[i + 1] != ' '))
		return (0);
	return (1);
}

int			verif_vect(char *line)
{
	int		i;

	if (ft_occ_nb(line, '{') != 1 || ft_occ_nb(line, '}') != 1)
		return (0);
	if (ft_occ_nb(line, ',') != 2 || ft_occ_nb(line, ' ') != 2)
		return (0);
	if (ft_occ_nb(line, '.') > 3 || ft_occ_nb(line, '-') > 3)
		return (0);
	if (line[0] != '{' || line[ft_strlen(line) - 1] != '}')
		return (0);
	i = 1;
	while (line[i + 1])
	{
		if (!ft_isdigit(line[i]))
		{
			if (!verif_vect_2(line, i))
				return (0);
		}
		i++;
	}
	return (1);
}
