#include "grimly.h"

void		map_init(t_env *env)
{
	size_t	i;

	i = -1;
	env->visited_map = (char*)malloc(sizeof(char) * env->card_x * env->card_x);
	ft_bzero(env->visited_map, sizeof(env->visited_map));
	while(env->map[++i])
	{
		if (env->map[i] == env->empty)
			env->visited_map[i] = -1;
		if (env->map[i] == env->obst)
			env->visited_map[i] = 0;
	}
}

t_map		*map_new(void)
{
	t_map	*temp;

	temp = (t_map*)malloc(sizeof(t_map));
	ft_bzero(temp, sizeof(t_map));
	return (temp);
}

int		find_in_map(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < ((env->card_y + 1) * env->card_x))
	{
		if (env->map[i] == env->entrance)
			return (i);
		i++;
	}
	return (-1);
}

t_map	*queue_init(t_env *env)
{
	t_map	*temp;
	int		x;
	int		y;

	temp = map_new();
	x = find_in_map(env);
	temp->curr_x = (x % (env->card_x + 1));
	temp->curr_y = (x / (env->card_x + 1));
	temp->last = NULL;
	env->visited_map[x] = 1;
	return (temp);
}

int			check_loc(t_env *env, t_map *curr)
{
	if (env->visited_map[x + (env->card_x * y)] == 0 && env->visited_map[x + (env->card_x * y)] != env->obst)
//check map bounds
// check visted map
//check board map
	return (0);
}

int			bfs_algo(t_env *env)
{
	t_map		*queue;
	t_map		*curr;

	map_init(env);
	queue = queue_init(env);
	while (env->map[curr->curr_x + (env->card_x * curr->curr_y)] != env->exit)  
	{

		if (check_loc(env, curr))
			add to queue
		if (left of curr exists && has not been visited)
			add to queue 
		if (down of queue exists && has not been visited)
			add to queue
		if (right of curr ecists && has not been visited)
			add to queue 
		if (no other possible connections)
			free node
	}
	trace_path(curr);
	return (1);
}