/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdarr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 23:52:49 by bmontoya          #+#    #+#             */
/*   Updated: 2017/06/21 00:48:34 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDARR_H
# define FTDARR_H
# include <stddef.h>

typedef struct	s_darr
{
	char		*arr;
	size_t		size;
	size_t		space;
	size_t		len;
}				t_darr;

t_darr			*ft_darrnew(size_t space, size_t size);
void			ft_darradd(t_darr *darr, void *data);
void			ft_darrdel(t_darr *darr);
void			ft_darrrm(t_darr *arr, size_t index);
void			ft_darrcat(t_darr *darr, void *data, size_t size);
#endif
