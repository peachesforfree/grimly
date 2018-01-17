/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:04:11 by sbalcort          #+#    #+#             */
/*   Updated: 2018/01/15 11:04:12 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H


# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_env
{
	int			fd;
	int			card_x;
	int			card_y;
	char		empty;
	char		fill;
	char		obst;
	char		entrance;
	char		exit;
	char		*map;
	int			entrance _cnt;
	int			exit_cnt;
}				t_env;

typedef struct		s_map
{
	size_t			last_x;
	size_t			last_y;
	size_t			curr_x;
	size_t			curr_y;

	struct s_map	up;
	struct s_map	left;
	struct s_map	down;
	struct s_map	right;
}				t_map;

#endif