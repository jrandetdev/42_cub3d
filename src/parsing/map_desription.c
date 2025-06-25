
#include "cub3d.h"

size_t	count_map_height(char **file)
{
	int	i;

	i = 6;
	while (file[i])
		i++;
	return (i - 6);
}

static size_t	get_max_row_size(char **file_content)
{
	size_t	len;
	size_t	max_len;

	max_len = 0;
	file_content += 6;
	while (*file_content)
	{
		len = ft_strlen(*file_content);
		if (len > max_len)
			max_len = len;
		file_content++;
	}
	return (max_len);
}

static char	*max_strdup(const char *s1, int max_size)
{
	char	*pointer;
	size_t	len;

	if (*s1 == '\0')
		return (ft_calloc(1, 1));
	len = ft_strlen(s1);
	pointer = ft_calloc(max_size + 1, sizeof(char));
	if (!pointer)
		return (NULL);
	ft_memcpy(pointer, s1, len + 1);
	return (pointer);
}

void	get_map_descritpion(t_main *main, char **file_content)
{
	int		i;
	int		j;
	int		height;
	int		width;

	i = 6;
	j = 0;
	height = count_map_height(file_content);
	width = get_max_row_size(file_content);
	main->map_struct.map = ft_calloc(height + 1, sizeof(char *));
	if (!main->map_struct.map)
		exit_cub3d(main, EXIT_FAILURE);
	while (file_content[i])
	{
		main->map_struct.map[j] = max_strdup(file_content[i], width);
		if (!main->map_struct.map[j])
		{
			safe_free_tab((void ***)&main->map_struct.map);
			exit_cub3d(main, EXIT_FAILURE);
		}
		j++;
		i++;
	}
	main->map_struct.width = width;
	main->map_struct.height = height;
}
