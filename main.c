/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 23:08:38 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:33:29 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <stdio.h>

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == EXIT)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env		*e;

	if (ac != 2)
		return (-1);
	e = (t_env*)malloc(sizeof(t_env));
	if (ft_parse(av[1], e) < 0)
	{
		ft_printf("ERROR !\n");
		exit(0);
	}
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, LAR, LON, "RAY's");
	ft_render(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
