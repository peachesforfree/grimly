/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:03:37 by sbalcort          #+#    #+#             */
/*   Updated: 2018/01/15 11:03:39 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			err(void)
{
	ft_putstr("SYNTAX ERR");
	return (0);
}

void		print_map(t_env *env)
{
	ft_putstr(env->map);
}

t_env		*env_init(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->fd = 0;
	env->card_x = 0;
	env->card_y = 0;
	env->empty = 0;
	env->fill = 0;
	env->entrance = 0;
	env->exit = 0;
	env->map = NULL;
	env->entrance_cnt = 0;
	env->exit_cnt = 0;
	return(env);
}

int			main(int argc, char **argv)
{
	t_env	*env;
	int		i;
	char	*test;

	i = 0;
	env = env_init();
	if (argc > 1)
	{
		while (++i < argc)
		{
			env->fd = open(argv[i], O_RDONLY);
			if (env->fd > 0 && read(env->fd, test, 0) > -1)
			{
				grimly(env);
				print_map(env);
				if (!bfs_algo(env))
					return (err());
			}
			else
				return (err());
		}
	}
	else
	{
		print_map(env);
		bfs_algo(env);
	}
	return (0);
}
