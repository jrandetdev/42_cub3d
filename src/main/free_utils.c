
#include "cub3d.h"

void	safe_free_tab(void ***ptr)
{
	int	i;

	i = 0;
	while ((*ptr)[i])
	{
		free((*ptr)[i]);
		(*ptr)[i++] = NULL;
	}
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_ptr_and_set_to_null(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	if (!array || !(*array))
		return ;
	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}
