
#ifndef BONUS_H
# define BONUS_H

#include <sys/time.h>

// MENU //
char	ft_capitalize(char letter);
void	menu_up(t_main *main, int *selection);
void	menu_down(t_main *main, int *selection);
void	print_menu_title(t_main *main, char *str);
void	show_option_menu(t_main *main, int *menu);
char	*ft_charjoin(char const *s1, char const s2);
void	print_correct_menu(t_main *main, int *menu);
void	show_main_menu(t_main *main, int *main_menu);
void	print_menu_section(t_main *main, int selection, int i, char *str);


// FPS //

#endif