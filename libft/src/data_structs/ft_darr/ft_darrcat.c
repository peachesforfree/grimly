/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 23:21:23 by bmontoya          #+#    #+#             */
/*   Updated: 2017/06/21 00:57:03 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dstruct/ftdarr.h>
#include <stddef.h>
#include <ftstring.h>
#include <stdlib.h>

void	ft_darrcat(t_darr *darr, void *data, size_t size)
{
	int		check;
	char	*tmp;

	check = 0;
	while (darr->size * (darr->space - darr->len) <= size)
	{
		check = 1;
		darr->space <<= 1;
	}
	if (check)
	{
		tmp = darr->arr;
		darr->arr = ft_memalloc(darr->space * darr->size);
		ft_memcpy(darr->arr, tmp, darr->len * darr->size);
		free(tmp);
	}
	ft_memcpy(darr->arr + (darr->len * darr->size), data, darr->size * size);
	darr->len += size / darr->size;
}
