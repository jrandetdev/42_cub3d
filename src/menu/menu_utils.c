
#include "cub3d.h"

static char *get_letter_filename(t_main *main, char letter, int i, int selection)
{
	const char	*path = "./Assets/xpm_letters";
	const char	*white = "_gold.xpm";
	const char	*gold = "_white.xpm";
	char 		*first_part;
	char		*filename;


	first_part = ft_strjoin(path, letter);
	if (!first_part)
		exit_cub3d(main, "'get_letter' malloc falied");
	if (selection == i)
		filename = ft_strjoin(first_part, gold);
	else
		filename = ft_strjoin(first_part, white);
	if (!filename)
	{
		free(first_part);
		exit_cub3d(main, "'get_letter' malloc falied");
	}
	return (filename);
}

static char ft_capitalize(char letter)
{
	if (letter >= "A" || letter <= 'Z')
		return (letter);
	return (letter ^ 32);
}

void	print_menu_title(t_main *main, int selection, int i, char *str)
{
	int			x;
	int			y;
	char		*filename;

	while (*str)
	{
		filename = get_letter_filename(main, *str, i, selection);
		
	}
}

// void	print_menu_title(t_main *main, int selection, int i, char *str)
// {
// 	int	x;
// 	int	y;

// 	x = WIN_WIDTH / 2;
// 	y = WIN_HEIGHT / 2 + i * 13;
// 	if (selection == i)
// 	{
// 		mlx_string_put(main->mlx_ptr, main->mlx_win, x , y, 0xFFCC00, str);
// 		return;
// 	}
// 	mlx_string_put(main->mlx_ptr, main->mlx_win, x , y, 0xFFFFFF, str);
// }