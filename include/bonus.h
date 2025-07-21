
#ifndef BONUS_H
# define BONUS_H

#include <sys/time.h>

// MENU //
char	ft_capitalize(char letter);
void	menu_up(t_main *main, int *selection);
void	menu_down(t_main *main, int *selection);
void	print_menu_title(t_main *main, char *str);
void	show_main_menu(t_main *main, int *main_menu);
void	print_menu_section(t_main *main, int selection, int i, char *str);

// FPS //

#endif