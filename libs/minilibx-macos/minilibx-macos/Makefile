MODULE_SRC = mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ = $(MODULE_SRC:.swift=.o)
MODULE_MOD = $(MODULE_SRC:.swift=.swiftmodule)

MAIN_SRC = interface.swift
MAIN_OBJ = $(MAIN_SRC:.swift=.o)

C_SRC = mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ = $(C_SRC:.c=.o)
CFLAGS = -O3 -w

FNAME = libmlx
NAME = libmlx.dylib
INC = -I.
#OPTI = -Ounchecked

all: compile_msg $(NAME)
	@echo "$(NAME) created."

compile_msg:
	@echo "$(FNAME) compiling..."

$(NAME): $(MODULE_OBJ) $(MAIN_OBJ) $(C_OBJ)
	@swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(MODULE_OBJ) $(MAIN_OBJ) $(C_OBJ) -lz

%.o %.swiftmodule: %.swift
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $(@:.swiftmodule=.o) -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<) 2>/dev/null

interface.o: interface.swift $(MODULE_MOD)
	@swiftc $(OPTI) $(INC) -c interface.swift -o interface.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(FNAME) cleaning..."
	@rm -f *.o *.swiftmodule *.swiftdoc *~ *.swiftsourceinfo *.json

fclean: clean
	@echo "$(NAME) cleaning..."
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re