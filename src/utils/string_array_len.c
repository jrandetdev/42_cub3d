
#include "cub3d.h"

size_t	string_array_len(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
