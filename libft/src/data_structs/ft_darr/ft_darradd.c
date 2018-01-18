/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 00:05:27 by bmontoya          #+#    #+#             */
/*   Updated: 2017/06/21 03:12:33 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dstruct/ftdarr.h>
#include <ftstring.h>
#include <stdlib.h>

void	ft_darradd(t_darr *darr, void *data)
{
	char	*tmp;

	if (darr->len + 1 < darr->space)
		ft_memcpy(darr->arr + (darr->len++ * darr->size), data, darr->size);
	else
	{
		tmp = darr->arr;
		darr->space <<= 1;
		darr->arr = ft_memalloc(darr->space * darr->size);
		ft_memcpy(darr->arr, tmp, darr->len * darr->size);
		free(tmp);
		ft_memcpy(darr->arr + (darr->len++ * darr->size), data, darr->size);
	}
}
