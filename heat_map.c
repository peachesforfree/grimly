#include "grimly.h"

int       *init_heat_map(t_env *env)
{
    int i;

    env->heat_map = (int*)malloc(sizeof(int) * (env->card_x * env->card_y));
    i = -1;
    while (++i < ((env->card_y) * env->card_x))
    {
        if (env->map[i] == env->obst)
            env->heat_map[i] = -1;
        if (env->map[i] == env->entrance)
            env->heat_map[i] = 0;
        if (env->map[i] == env->empty)
            env->heat_map[i] = 0;
        if (env->map[i] == env->exit)
            env->heat_map[i] = 1;
    }
    return (env->heat_map);
}

void    check_values(t_map *map, t_env *env)
{
    if ((map->y - 1 > 0) && map->map[map->x * (map->y - 1 * env->card_x)] > 0)//check for up
        map->map[map->x * (map->y - 1 * env->card_x)] = map->map[map->x * (map->y * env->card_x)] + 1;
    if ((map->x - 1 > 0) && map->map[map->x - 1 * (map->y * env->card_x)] > 0)//check for left
        map->map[map->x - 1 * (map->y * env->card_x)] = map->map[map->x - 1 * (map->y * env->card_x)] + 1;
    if ((map->y + 1 < env->card_y) && map->map[map->x * (map->y + 1 * env->card_x)] > 0)//check for down
        map->map[map->x * (map->y + 1 * env->card_x)] = map->map[map->x * (map->y + 1 * env->card_x)] + 1;
    if ((map->x + 1 < env->card_x) && map->map[map->x + 1 * (map->y * env->card_x)] > 0)//check for right
        map->map[map->x + 1 * (map->y * env->card_x)] = map->map[map->x + 1 * (map->y * env->card_x)] + 1;
}

void    print_heat_map(t_map *map, t_env *env)
{
    int     x;
    int     y;
    
    y = -1;
    while (++y < env->card_y)
    {
        x = -1;
        while (++x < env->card_x)
        {
            ft_putnbr(map->map[x + (y * env->card_x)]);
        }
        ft_putchar('\n');
    }
}
int     heat_map(t_env *env)
{
    t_map   map;
    
    map.number = 1;
    map.map = init_heat_map(env);
    print_heat_map(&map, env);
    ft_putchar('\n');
    while (++map.number)
    {
        map.count = 0;
        map.y = -1;
        while (++map.y < env->card_y)
        {
            map.x = -1;
            while (++map.x < env->card_x)
            {
                if (map.map[map.x + (map.y * env->card_x)] > 0)
                {
                    check_values(&map, env);
                    map.count++;
                }
            }
        }
        if (map.count == 0)
            break ;
    }
    print_heat_map(&map, env);
    return (1);
}