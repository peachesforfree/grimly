#include "grimly.h"

void        env_init(void)
{
    t_env   *temp;

    temp = (t_env*)malloc(sizeof(t_env));
    env->fd = 0;


}

int         main(int argc, char **argv)
{
    t_env   *env;
    int     i;

    i = -1;
    env = env_init();
    if (argc > 1) 
    {
        while (++i < argc)
        {
            env->fd = open(argv[i], O_RDONLY);
            grimly(env);
        }
    }
    else
		grimly(env);
    return (0);
}