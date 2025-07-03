
#include "cub3d.h"

static void	flood_fill(t_parsing *p, int x, int y)
{
	if (p->patern == 1)
		return ;
	if (x < 0 || y < 0 || y >= p->map_height || x >= p->map_width || p->map[y][x] == '\0' || p->map[y][x] == ' ')
	{
		p->patern = 1;
		return ;
	}
	if (p->map[y][x] == '1' || p->map[y][x] == 'V')
		return ;
	p->map[y][x] = 'V';
	if (p->patern == 1)
		return ;
	flood_fill(p, x + 1, y);
	flood_fill(p, x, y + 1);
	flood_fill(p, x - 1, y);
	flood_fill(p, x, y - 1);
	flood_fill(p, x + 1, y + 1);
	flood_fill(p, x - 1, y - 1);
	flood_fill(p, x + 1, y - 1);
	flood_fill(p, x - 1, y + 1);
}

static char	**copy_map(char **map, t_parsing *parsing)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = ft_calloc(parsing->map_height + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[j] = max_strdup(map[i++], parsing->map_width); //add ft_strdup_max
		if (!new_map[j])
		{
			safe_free_tab((void ***)&new_map);
			return (NULL);
		}
		j++;
	}
	return (new_map);
}

void	is_map_valid(t_main *main)
{
	int			x;
	int			y;
	t_parsing	parsing;

	x = 0;
	y = 0;
	if (main->map_struct.height < 3 || main->map_struct.width < 3)
		exit_cub3d(main, "map too small");
	ft_bzero(&parsing, sizeof(t_parsing));
	main->player.x = 4; //debug
	main->player.y = 10; //debug
	if (!find_player_position(main, &x, &y, &parsing.player)) //FIND PLAYER MISSING ?
		exit_cub3d(main, "Player not found.");
	parsing.map_height = main->map_struct.height;
	parsing.map_width = main->map_struct.width;
	parsing.map = copy_map(main->map_struct.map, &parsing);
	if (!parsing.map)
		exit_cub3d(main, "Map could not be copied in is_map_valid.");
	flood_fill(&parsing, x, y);
	safe_free_tab((void ***)&parsing.map);
	// if ((parsing.patern) == 1) //debug
	// 	exit_cub3d(main, "Map invalid"); //debug
}
