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

int			bound_check(int x, int y, t_env *env)
{
	if (x < 0)
		return (0);
	if (x >= env->card_x)
		return (0);
	if (y < 0)
		return (0);
	if (y >= env->card_y)
		return (0);
	return (1);
}

/*
**examines the visited map for if that location has been visited
**if not, the map is marked as visited and returns 1, else 0.
*/

int			check_loc(t_env *env, int y, int x)
{
	if (env->visited_map[x + (env->card_x * y)] == 1)
		return (0);
	else
		env->visited_map[x + (env->card_x * y)] = 1;
	return (1);
}

void		trace_path(t_map *lst, t_env *env)
{
	while (lst->last != NULL)
	{
		env->map[lst->curr_x + (lst->curr_y * env->card_x)] = env->obst;
		lst = lst->last;
	}
}

int			bfs_algo(t_env *env)
{
	t_map		*queue;
	t_map		*end_q;
	t_map		*temp;
	t_map		*curr;

	map_init(env);
	queue = queue_init(env);
	end_q = queue;
	while (env->map[curr->curr_x + (env->card_x * curr->curr_y)] != env->exit)
	{
		if (bound_check((curr->curr_y - 1) , curr->curr_x, env) && check_loc(env, curr->curr_y - 1, curr->curr_x)) // traverse up
		{
			temp = map_new();
			temp->curr_x = curr->curr_x;
			temp->curr_y = curr->curr_y - 1;
			temp->last = curr;
			curr->up = temp;
			end_q->next = temp;
			end_q = temp;
			temp = NULL;
		}
		if (bound_check((curr->curr_y) , curr->curr_x - 1, env) && check_loc(env, curr->curr_y, curr->curr_x - 1))	//traverse left
		{
			temp = map_new();
			temp->curr_x = curr->curr_x - 1;
			temp->curr_y = curr->curr_y;
			temp->last = curr;
			curr->left = temp;
			end_q->next = temp;
			end_q = temp;
			temp = NULL;
		}
		if (bound_check((curr->curr_y + 1) , curr->curr_x, env) && check_loc(env, curr->curr_y + 1, curr->curr_x))	//traverse down
		{
			temp = map_new();
			temp->curr_x = curr->curr_x;
			temp->curr_y = curr->curr_y + 1;
			temp->last = curr;
			curr->right = temp;
			end_q->next = temp;
			end_q = temp;
			temp = NULL;

		}
		if (bound_check((curr->curr_y) , curr->curr_x + 1, env) && check_loc(env, curr->curr_y, curr->curr_x + 1))	//traverse right
		{
			temp = map_new();
			temp->curr_x = curr->curr_x + 1;
			temp->curr_y = curr->curr_y;
			temp->last = curr;
			curr->right = temp;
			end_q->next = temp;
			end_q = temp;
			temp = NULL;
		}
		curr = curr->next;
	}
	trace_path(end_q, env);
	return (1);
}