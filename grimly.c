/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:03:57 by sbalcort          #+#    #+#             */
/*   Updated: 2018/01/15 11:04:34 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void		parse_line(t_env *env, char *line)
{
	size_t	i;

	i = ft_strlen(line);
	line[i--] = env->exit;
	line[i--] = env->entrance;
	line[i--] = env->fill;
	line[i--] = env->empty;
	line[i--] = env->obst;
	while (ft_isdigit(line[i]))
		i--;
	env->card_x = ft_atoi(line[i + 1]);
	if (line[--len] != x)
		return (err(void));
	if (env->card_x < 5 || env->card_y < 5)
		return (err(void));
	env->card_y = ft_atoi(line);
}

/*
**here check the map string for valid number of columns, rows, and chars.
*/

int		check_valid_map(t_env *env)
{
	size_t x;
	size_t y;

	x = -1;
	y = -1;
	while ()
	{
		while ()
		{
			
		}

	}
	return (1);
}

/*
**here the card is read and all values recorded
**map validity is also checked
*/

int		read_card(t_env *env)
{
	size_t	bytes_read;
	char	*line;

	bytes_read = 0;
	get_next_line(env->fd, line);
	parse_line(env, line);
	env->map = (char*)malloc((env->card_x + 1) * (env->card_y) + 1);
	env->map[(env->card_x + 1) * (env->card_y) + 1];
	bytes_read = read(env->fd, env->map, ((env->card_x + 1) * (env->card_y)));
	if (bytes_read != (env->card_x + 1) * (env->card_y))
		return (0);
	env->map[(env->card_x + 1) * (env->card_y) + 1] = '\0';
	if (!check_valid_map(env))
		return (0);

	return (1);
}

int		grimly(t_env *env)
{
    //first take care of reading
    if (!read_card(env))
		return(0);
    //then parsing and storing
    // then research algorithms for path finding
	return (1);
}
