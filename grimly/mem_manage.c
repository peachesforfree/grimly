#include "grimply.h"

t_map		*tmap_new(void)
{
	t_map	*temp;

	temp = (t_map*)malloc(sizeof(t_map));
	ft_bzero(temp, sizeof(t_map));
	return (temp);
}