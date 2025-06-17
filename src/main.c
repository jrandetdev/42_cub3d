/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:27:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/17 17:07:39 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//floodfill
	// faire un floodfill 
	//point de depart, un seul N S W E 
		// toutes conditions a respecter 
		//si c'est un V, si c'est un mur, ou un esapce
		//jamais atteindrele /0 et jamais un index -1 
		//condition d'arret: tout ce qui n'est pas 1 (si 0 a la fin de la map)

//static int	read_from_fd

static int	get_fd_for_reading(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	printf("fd is worth %d\n", fd);
	if (fd == -1)
		return (-1);
	return (fd);
}

static bool	cub_extension_is_valid(char	*s, int len)
{
	while (*s)
		s++;
	s--;
	if (*s != 'b')
		return (false);
	while (len--)
		s--;
	if (ft_strncmp(s, ".cub", 4) == 0)
		return (true);
	return (false);
}

static bool	arguments_are_valid(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error_and_message("Please give only one file as input.\n");
		return (false);
	}
	if (!cub_extension_is_valid(argv[1], 3))
	{
		print_error_and_message(".cub extenssion is missing.\n");
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	t_main	main;
	int		fd;

	ft_bzero(&main, sizeof(t_main));
	if (!arguments_are_valid(argc, argv))
		return (EXIT_FAILURE);
	fd = get_fd_for_reading(argv[1]);
	if (fd == -1)
		return (EXIT_FAILURE);
	printf("file is successfully openned, fd is %d\n", fd);
	//read_fd_and_extract(&main, fd);
	//tableau de char ou de int, plus grande longeur
	//tableau 2 dimenssions "buffer ou map"

	// espaces gardes en tant qu-espace isspace 
	return (0);
}
