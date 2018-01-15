#include "grimly.h"

void        read_card(t_env *env)
{
    size_t  bytes_read;
    char    *line;

    bytes_read = 0;
    get_next_line(env->fd, line);
    parse_line(env, line);
    while ()
    {



    }


}

void        grimly(t_env *env)
{
    //first take care of reading
    read_card(env);
    //then parsing and storing
    // then research algorithms for path finding
}