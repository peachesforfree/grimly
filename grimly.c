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

int			parse_line(t_env *env, char *line)
{
	size_t	i;

	i = ft_strlen(line);
	i--;
	env->exit = line[i--];
	env->entrance = line[i--];
	env->fill = line[i--];
	env->empty = line[i--];
	env->obst = line[i];
	line[i] = '\0';
	i = 0;
	if (!ft_isdigit(line[i]))
		return (0);
	env->card_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != 'x')
		return (0);
	i++;
	env->card_x = ft_atoi(&line[i]);
	//put in here somewhere the check for muliple reoccuring chars
	//another function to check 
	return (1);
}

int		char_check(t_env *env, char c)
{
	if (c == env->obst)
		return (1);
	if (c == env->empty)
		return (1);
	if (c == env->entrance)
	{
		env->entrance_cnt++;
		return (1);
	}
	if (c == env->exit)
	{
		env->exit_cnt++;
		return (1);
	}
	return (0);
}

/*
**here check the map string for valid number of columns, rows, and chars.
*/

int			check_valid_map(t_env *env)
{
	size_t	x;
	size_t	y;
	char	*map;

	map = env->map;
	y = -1;
	while (++y < env->card_y)
	{
		x = -1;
		while (++x < (env->card_x - 1))
		{
			if (!char_check(env, map[x + (y * env->card_x)]))
				return (0);
		}
		if (map[x + (y * x)] != '\n')
			return (0);
	}
	if (env->entrance_cnt != 1 || env->exit_cnt < 1)
		return (0);
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
	get_next_line(env->fd, &line);
	if (!parse_line(env, line))
		return (0);
	env->map = (char*)malloc((env->card_x + 1) * (env->card_y) + 1);
	//env->map[(env->card_x + 1) * (env->card_y) + 1];
	bytes_read = read(env->fd, env->map, ((env->card_x + 1) * (env->card_y)));
	if (bytes_read != (env->card_x + 1) * (env->card_y))
		return (0);
	env->map[(env->card_x + 1) * (env->card_y) + 1] = '\0';
	return (1);
}

int		grimly(t_env *env)
{
	if (!read_card(env))
		return (0);
	//if (!check_valid_map(env))
	//	return (0);
	//if (!bfs_algo(env))
	//	return (0);
	return (1);
}
