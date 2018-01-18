/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrrm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:22:22 by bmontoya          #+#    #+#             */
/*   Updated: 2017/06/21 05:23:52 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dstruct/ftdarr.h>
#include <ftstring.h>

void	ft_darrrm(t_darr *arr, size_t index)
{
	if (index < arr->len)
	{
		--arr->len;
		if (arr->len)
		{
			ft_memcpy(arr->arr + index * arr->size,
			arr->arr + (index + 1) * arr->size,
			arr->len * arr->size);
		}
		ft_memset(arr->arr + arr->len * arr->size, 0, arr->size);
	}
}
