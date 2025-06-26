
#include "cub3d.h"

static bool	is_in_char_range(char *s)
{
	if (ft_strlen(s) == 3)
	{
		if (s[0] > '2' || s[1] > '5' || s[2] > '5')
			return false;
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
	return (false);
}

void	validate_colour(t_main *main, char **splitted_colours)
{
	int	i;

	i = 0;
	while (splitted_colours[i])
	{
		if (!is_valid_len(splitted_colours[i]))
		{
			free_string_array(&splitted_colours);
			return (exit_cub3d(main, "Colour must be between 1 and 3 digits."));
		}
		if (!is_only_digit(splitted_colours[i]))
		{
			free_string_array(&splitted_colours);
			exit_cub3d(main, "Colour cannot contain other characters than digits.");
		}
		if(!is_in_char_range(splitted_colours[i]))
		{
			free_string_array(&splitted_colours);
			exit_cub3d(main, "RGB values must be between 0 - 255");
		}
		i++;
	}
}
