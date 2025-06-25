
#include "cub3d.h"

static bool	is_in_char_range(char *s)
{
	if (ft_strlen(s) == 3)
	{
		if (s[0] > '2' || s[1] > '5' || s[2] > '5')
		{
			print_error_and_message("Floor or Ceiling: please only \
				give colours between 0 and 255.\n");
			return false;
		}
	}
	return (true);
}

static bool	is_only_digit(char *colour)
{
	while (*colour)
	{
		if (!ft_isdigit(*colour))
			return (false);
		colour++;
	}
	return (true);
}

static bool	is_valid_len(char *colour)
{
	int	len;

	len = ft_strlen(colour);
	if (1 <= len && len <= 3)
		return (true);
	print_error_and_message("Colour must be between 1 and 3 digits\n");
	return (false);
}

bool	is_valid_colours(t_main *main, char **splitted_colours)
{
	int	i;

	i = 0;
	while (splitted_colours[i])
	{
		if (!is_valid_len(splitted_colours[i]) \
			|| !is_only_digit(splitted_colours[i])
			|| !is_in_char_range(splitted_colours[i]))
		{
			free_string_array(&splitted_colours);
			exit_cub3d(main, 1);
			return (false);
		}
		i++;
	}
	return (true);
}
