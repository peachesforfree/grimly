#include "grimly.h"

void		map_init(t_env *env)
{
	size_t	i;

	i = -1;
	env->visited_map = (char*)malloc(sizeof(char) * env->card_x * env->card_x);
	ft_bzero(env->visited_map, sizeof(env->visted_map));
	while(env->map[++i])
	{
		if (env->map[i] == empty)
			env->visited_map = -1;
		if (env->map[i] == obst)
			env->visted_map = 0;
	}
}

int		bfs_algo(t_env *env)
{
	t_map	*queue;
	t_map	*curr;
	int		x;
	int		y;

	y = -1;
	x = -1;
	map_init(env);
	queue = 
	
	return (1);
}