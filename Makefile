NAME			=	cub3d

BONUS			=	cub3d_bonus

CFLAGS			=	-Wall -Werror -Wextra

DEBUG 			= 	0

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

ifeq ($(DEBUG), 2)
	CFLAGS += -g2
endif

ifeq ($(DEBUG), 3)
	CFLAGS += -g3
endif

ifeq ($(DEBUG), 4)
	CFLAGS += -g3 -fsanitize=address
endif

LIBFT			=	libft.a

LIBFT_PATH		=	libft/

MLX				=	libmlx_Linux.a

MLX_FLAG 		=	-Lmlx -Lminilibx-linux -L/usr/lib/X11 -lXext -lX11

MATH_FLAG		=	-lm -lz

TXT				=	compile_flags.txt

MLX_PATH		=	minilibx-linux/

HEADER			=	-I./include -I./libft/include -I./${MLX_PATH}

HEADER_FILES	=	include/cub3d.h \
					include/structures.h \
					libft/include/ft_printf.h \
					libft/include/get_next_line.h \
					libft/include/libft.h \

GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
YELLOW    		=	\033[;33m
BWHITE    		=	\033[1;37m
RESET			=	\033[0m
ITALIC			=	\e[3m
BOLD			=	\e[1m
NEW				=	\r\033[K

SRC_PATH		=	src/

OBJ_PATH		=	obj/

CC				=	cc

RM				=	rm -rf

AR				=	ar rcs

SRCS_MAIN		=	parsing/parse_map.c \
					parsing/texture_parsing.c \
					parsing/check_line.c \
					parsing/check_map.c \
					parsing/error.c \
					parsing/free_parsing.c \
					parsing/is_char.c \
					parsing/start_coord.c \
					parsing/parsing_get_color.c \
					parsing/parsing_utils.c \
					debug.c \
					cub3d.c \
					raycasting/do_dda.c \
					raycasting/calculate_delta.c \
					raycasting/calculate_step.c \
					raycasting/calculate_perp_wall_dist.c \
					draw/put_pixel_on_img.c \
					draw/draw_line_on_img.c \
					draw/draw_ceiling.c \
					draw/draw_floor.c \
					draw/draw_pov.c \
					draw/draw_wall_line.c \
					img/get_new_img.c \
					camera_movement/read_key.c \
					camera_movement/move.c \
					camera_movement/rotate.c \
					camera_movement/starting_rotate.c \
					end_process.c \

OBJS			=	$(addprefix ${OBJ_PATH}, ${SRCS_MAIN:.c=.o}) \

LIBFT_D			=	$(addprefix ${LIBFT_PATH}, ${LIBFT})

SRCS_TEST		=	raycasting/test_rc.c \
					raycasting/do_dda.c \
					raycasting/calculate_delta.c \
					raycasting/calculate_step.c \
					raycasting/calculate_perp_wall_dist.c \
					draw/put_pixel_on_img.c \
					draw/draw_line_on_img.c \
					draw/draw_ceiling.c \
					draw/draw_floor.c \
					draw/draw_pov.c \
					draw/draw_wall_line.c \
					img/get_new_img.c \
					camera_movement/read_key.c \
					camera_movement/move.c \
					camera_movement/rotate.c \
					camera_movement/is_move_available.c \
					end_process.c

OBJS_TEST		=	$(addprefix ${OBJ_PATH}, ${SRCS_TEST:.c=.o}) \
################################################################################
#                                 RULES                                        #
################################################################################
					
all:			${NAME}

bonus:			${BONUS}

${NAME}:		${MLX} ${LIBFT} ${OBJS} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@printf "${NEW}${YELLOW}${NAME}${RESET}${GREEN}${BOLD} Compiled\n${RESET}${GREEN}compiled with:${RESET} ${CC} ${CFLAGS}\n"

test.exe:		${MLX} ${LIBFT} ${OBJ} ${OBJS_TEST} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o test.exe ${OBJ} ${OBJS_TEST} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@echo "${lsCOLOUR_GREEN}test.exe Compiled${COLOUR_END}"

${BONUS}:		${MLX} ${LIBFT} ${OBJS} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o ${BONUS} ${OBJS} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@echo "${COLOUR_GREEN}${BONUS} Compiled${COLOUR_END}"

${OBJ_PATH}%.o:	${SRC_PATH}%.c ${HEADER_FILES}
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} ${HEADER} -c $< -o $@
		@printf "${NEW}${YELLOW} ${NAME} ${GREEN}Building: ${RESET}${CC} ${CFLAGS} ${ITALIC}${BOLD}$<${RESET}"

txt:			${TXT}

${LIBFT}:
		@make -C ${LIBFT_PATH} DEBUG=$(DEBUG) --no-print-directory
		@cp ${LIBFT_PATH}${LIBFT} .

${MLX}:
		${RM} ${MLX_PATH}
		git clone https://github.com/42Paris/minilibx-linux
		@make -C ${MLX_PATH} --no-print-directory
		@cp ${MLX_PATH}${MLX} .
		@echo "$(COLOUR_GREEN)MLX compiled${COLOUR_END}"

${TXT}:
		@echo "-Ilibft/include\n-Iinclude/\n-Iminilibx-linux/" > compile_flags.txt
		@echo "-I../libft/include\n-I../include/\n-I../minilibx-linux" > src/compile_flags.txt

clean:
		@make -C ${LIBFT_PATH} clean --no-print-directory
		@make -C ${MLX_PATH} clean --no-print-directory
		${RM}  ${OBJ_PATH}

fclean:		clean
		@make -C ${LIBFT_PATH} fclean --no-print-directory
		${RM} ${MLX_PATH}
		${RM} ${NAME} ${NAME_TEST} ${BONUS} ${LIBFT} ${MLX} ${SRC_PATH}${TXT} ${SRC_PATH}bonus/${TXT} ${TXT}

re:			fclean all

.PHONY:		all fclean clean re libft


