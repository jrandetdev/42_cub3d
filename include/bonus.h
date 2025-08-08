
#ifndef BONUS_H
# define BONUS_H

#include <sys/time.h>
#include <pthread.h>

# ifndef BONUS
#  define BONUS 1
# endif

# define N_THREAD 10
# define MAX_SENSITIVITY 100
# define MIN_SENSITIVITY 1

# define DC '2'
# define DO '3'
# define DA '4'
# define DOOR_ANIMATION_SPEED 0.05

#include "struct.h"
#include "bonus_struct.h"

enum DOOR_STATE
{
	NONE = 0,
	OPENING = 1,
	CLOSING = 2,
};

/*--------------------------------- MENU -------------------------------------*/

char	ft_capitalize(char letter);
void	show_debug_menu(t_main *main, int *menu);
void	print_menu_title(t_main *main, char *str);
void	show_option_menu(t_main *main, int *menu);
char	*ft_charjoin(char const *s1, char const s2);
void	print_correct_menu(t_main *main, int *menu);
void	show_main_menu(t_main *main, int *main_menu);
void	show_pause_menu(t_main *main, int *main_menu);
void	menu_up_and_down(t_main *main, int *selection);
void	show_mouse_sensitivity_menu(t_main *main, int *menu);
void	print_menu_section(t_main *main, t_menu_struct *param, char *str);
void	print_box(t_main *main, t_menu_struct *menu, int param, char *str);

/*--------------------------------- FPS --------------------------------------*/
void	fps_counter(t_main *main);

/*--------------------------------- DOOR -------------------------------------*/
void	change_door_state(t_main *main);
void	player_action(t_main *main);
void	playing_door_animation(t_main *main);
bool	is_in_door_half(t_main *main, t_dda_struct *dda);

/*----------------------------- FLOOR CEILING --------------------------------*/
void	draw_floor_and_ceiling(t_main *main, int x, int y, float z);

#endif