
#include "cub3d.h"

static bool	get_players(char **map, int *x, int *y, int *player)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!ft_strchr("01NSWE' ", map[j][i]))
				return (print_error_and_message("unknown character"), false);
			if (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E')
			{
				*x = i;
				*y = j;
				(*player)++;
			}
			i++;
		}
		j++;
	}
	return (true);
}

static bool	find_player_postion(t_main *main, int *x, int *y, int *player)
{
	if (!get_players(main->map_struct.map, x, y, player))
		return (false);
	if (*player != 1)
	{
		if (*player < 1)
			exit_cub3d(main, "No player found");
		else if (*player > 1)
			exit_cub3d(main,"Too many players, it's a single-player game");
		return (false);
	}
	main->player.x = *x;
	main->player.y = *y;
	return (true);
}

static void	flood_fill(t_parsing *p, int x, int y)
{
	if (p->patern == 1)
		return ;
	if (x < 0 || y < 0 || y >= p->map_height || p->map[y][x] == '\0' || p->map[y][x] == ' ')
	{
		p->patern = 1;
		return ;
	}
	if (p->map[y][x] == '1' || p->map[y][x] == 'V')
		return ;
	p->map[y][x] = 'V';
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
	printf("\nHEIGT %d, WIDTH %d\n\n", main->map_struct.height, main->map_struct.width);
	if (main->map_struct.height < 3 || main->map_struct.width < 3)
		exit_cub3d(main, "map too small");
	ft_bzero(&parsing, sizeof(t_parsing));
	if (!find_player_postion(main, &x, &y, &parsing.player))
		exit_cub3d(main, "Player not found.");
	parsing.map_height = main->map_struct.height;
	parsing.map_width = main->map_struct.width;
	parsing.map = copy_map(main->map_struct.map, &parsing);
	if (!parsing.map)
		exit_cub3d(main, "Map could not be copied in is_map_valid.");
	flood_fill(&parsing, x, y);
	safe_free_tab((void ***)&parsing.map);
	if ((parsing.patern) == 1)
		exit_cub3d(main, "Map invalid");
}
