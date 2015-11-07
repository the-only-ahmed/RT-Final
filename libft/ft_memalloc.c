/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:32:00 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/26 20:00:28 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pointer;

	pointer = (void*)malloc(size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, size);
	return (pointer);
}
