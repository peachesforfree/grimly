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

void		env_init(void)
{
	t_env	*temp;

	temp = (t_env*)malloc(sizeof(t_env));
	env->fd = 0;
	env->empty = 0;
	env->fill = 0;
	env->entrance = 0;
	emv->exit = 0;
}

int			main(int argc, char **argv)
{
	t_env	*env;
	int		i;

	i = -1;
	env = env_init();
	if (argc > 1)
	{
		while (++i < argc)
		{
			env->fd = open(argv[i], O_RDONLY);
			if(!grimly(env))
				return (err(void));
		}
	}
	else
		grimly(env);
	return (0);
}
