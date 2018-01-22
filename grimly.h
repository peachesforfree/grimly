/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:04:11 by sbalcort          #+#    #+#             */
/*   Updated: 2018/01/17 20:22:15 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H


# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

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
	int			*heat_map;
	int			entrance_cnt;
	int			exit_cnt;
}				t_env;

typedef struct	s_map
{
	int			*map;
	int			number;
	int			x;
	int			y;
	int			count;
}				t_map;

int				main(int argc, char **argv);
int				grimly(t_env *env);
int				err(void);
int				heat_map(t_env *env);

#endif
