
#Colors:
########################
BOLD = \033[1m
BLUE = \033[0;34m
CYAN = \033[36m
GREEN = \033[32m
ORANGE = \033[93m
PURPLE = \033[0;95m
RED = \033[0;91m
END = \033[0m
########################

NAME	        =		so_long

NAME_B          =       so_long_bonus

SRCS            =       srcs/event_manager.c\
						srcs/exit_lose.c\
						srcs/exit_win.c\
						srcs/ft_drawing.c\
						srcs/load_texture.c\
						srcs/movement.c\
						srcs/parsing.c\
						srcs/parsing2.c\
						srcs/so_long.c\
						srcs/utils.c

SRCS_B      =       	bonus/srcs_bonus/draw_counter_bonus.c\
						bonus/srcs_bonus/event_manager_bonus.c\
						bonus/srcs_bonus/exit_lose.c\
						bonus/srcs_bonus/exit_win.c\
						bonus/srcs_bonus/ft_drawing_bonus.c\
						bonus/srcs_bonus/load_texture_bonus.c\
						bonus/srcs_bonus/movement_bonus.c\
						bonus/srcs_bonus/movement2_bonus.c\
						bonus/srcs_bonus/movement_dofi_bonus.c\
						bonus/srcs_bonus/parsing_bonus.c\
						bonus/srcs_bonus/parsing2_bonus.c\
						bonus/srcs_bonus/so_long_bonus.c\
						bonus/srcs_bonus/utils_bonus.c

INCLUDES_DIR     =      includes/

INCLUDES_DIR_B  =       bonus/includes_bonus/

LIB_DIR         =       libft/

LIBFT           =       libft/libft.a

CC              =       clang

OBJS            =       ${SRCS:.c=.o}

OBJS_B          =       ${SRCS_B:.c=.o}

MLX         =       minilibx-linux/libmlx_Linux.a

MLX_DIR     =       minilibx-linux/

RM          =       rm -rf

LFLAGS       =       -lm -lX11 -lXext -lbsd

FLAGS       =       -Wall -Wextra -Werror -g

.c.o:
						@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
						@echo "\t\t${BOLD}${GREEN}${END} ${PURPLE}${<:.s=.o}${END}"

all:			${NAME}

${NAME}:		${OBJS}
						@make -C ${LIB_DIR}
						@${CC} ${FLAGS} ${LFLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}
						@echo "\t\t${BOLD}${CYAN} mlx.a${END}   ${GREEN}\r[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN} libft.a${END}   ${GREEN}\r[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN} so_long${END}   ${GREEN}\r[ OK ]\n${END}"
						@echo "\t${BOLD}${ORANGE} ------------------------------------------------------------------------\n${END}"
						@echo "\t\t${BOLD}${ORANGE} Help Luffy collect the meat before heading back to sea !\n${END}"
						@echo "\t${BOLD}${ORANGE} ------------------------------------------------------------------------\n${END}"

bonus:		${OBJS_B}
						@make -C ${LIB_DIR}
						@${CC} ${FLAGS} ${LFLAGS} -I${INCLUDES_DIR_B} -o ${NAME_B} ${OBJS_B} ${LIBFT} ${MLX}
						@echo "\t\t${BOLD}${CYAN} mlx.a${END}   ${GREEN}\r[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN} libft.a${END}   ${GREEN}\r[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN} so_long_bonus${END}   ${GREEN}\r[ OK ]\n${END}"
						@echo "\t${BOLD}${ORANGE} ------------------------------------------------------------------------\n${END}"
						@echo "\t\t${BOLD}${ORANGE} Help Luffy collect the meat before heading back to sea !\n${END}"
						@echo "\t\t\t${BOLD}${ORANGE}       Watch out for Doflamingo !\n${END}"
						@echo "\t${BOLD}${ORANGE} ------------------------------------------------------------------------\n${END}"

clean:
						@make -C ${LIB_DIR} clean
						@${RM} ${OBJS} ${OBJS_B}
						@echo "\n${BOLD}${RED}\t\t *.o files deleted.${END}"

fclean:		clean
						@make -C ${LIB_DIR} fclean
						@${RM} ${NAME} ${NAME_B}
						@echo "\t\t${BOLD}${RED}libft.a deleted.${END}"
						@echo "\t\t${BOLD}${RED}Program so_long deleted.${END}"
						@echo "\t\t${BOLD}${RED}Program so_long_bonus deleted.${END}"

re:		fclean all

.PHONY:           all     clean   fclean  re
