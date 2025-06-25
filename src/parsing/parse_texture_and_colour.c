
#include "cub3d.h"

bool	parse_texture_or_colour(t_main *main, char **splitted_elements)
{
	char	*identifier;
	char	*information;
	int		id_len;

	if (splitted_elements[1] == NULL)
		return (false);
	identifier = splitted_elements[0];
	information = splitted_elements[1];
	id_len = ft_strlen(identifier);
	if (id_len > 2 || id_len < 1)
		return (false);
	if (id_len == 2)
		return (extract_texture(main, identifier, information));
	else
		return (extract_fc_colour(main, identifier, information));
}

void	extract_map_elements(t_main *main, char **file)
{
	int		i;
	char	**splitted_map_line;

	i = 0;
	while (i <= 5)
	{
		splitted_map_line = ft_split(file[i], ' ');
		if (!splitted_map_line)
			exit_cub3d(main, 1);
		if (string_array_len(splitted_map_line) != 2)
		{
			print_error_and_message("Invalid Map element, please enter an \
				identifier and the relative path to the texture file or \
				the R,G,B colour codes for ceiling/floor\n");
			free_string_array(&splitted_map_line);
			exit_cub3d(main, 1);
		}
		if (!parse_texture_or_colour(main, splitted_map_line))
		{
			free_string_array(&splitted_map_line);
			exit_cub3d(main, 1);
		}
		free_string_array(&splitted_map_line);
		i++;
	}
}
