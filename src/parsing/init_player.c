#include "cub3d.h"

static void	initialise_north_and_south(t_main *main)
{
	if (ft_strncmp(main->player.orientation, "N", 1) == 0)
	{
		main->player.forward_x = 0;
		main->player.forward_y = -1;
		main->player.right_x = 0.66;
		main->player.right_y = 0;
	}
	if (ft_strncmp(main->player.orientation, "S", 1) == 0)
	{
		main->player.forward_x = 0;
		main->player.forward_y = 1;
		main->player.right_x = -0.66;
		main->player.right_y = 0;
	}
}

static void	initialise_east_and_west(t_main *main)
{
	if (ft_strncmp(main->player.orientation, "E", 1) == 0)
	{
		main->player.forward_x = 1;
		main->player.forward_y = 0;
		main->player.right_x = 0;
		main->player.right_y = 0.66;
	}
	if (ft_strncmp(main->player.orientation, "W", 1) == 0)
	{
		main->player.forward_x = -1;
		main->player.forward_y = 0;
		main->player.right_x = 0;
		main->player.right_y = -0.66;
	}
}

static void	init_player_direction(t_main *main)
{
	initialise_north_and_south(main);
	initialise_east_and_west(main);
	main->player.angle = atan2(main->player.forward_y, main->player.forward_x);
}

static bool	get_players(t_main *main, char **map, int *x, int *y, int *player)
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
				main->player.orientation = &(map[j][i]);
				(*player)++;
			}
			i++;
		}
		j++;
	}
	return (true);
}

bool	find_player_position(t_main *main, int *x, int *y, int *player)
{
	if (!get_players(main, main->map_struct.map, x, y, player))
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
	init_player_direction(main);
	return (true);
}