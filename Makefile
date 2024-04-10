# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:32:25 by ldoyen--          #+#    #+#              #
#    Updated: 2024/04/09 14:18:57 by xabaudhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
					include/camera_movement.h \
					include/draw.h \
					include/raycasting.h \
					include/parsing.h \
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

RM				=	rm -f -r

AR				=	ar rcs

SRCS_MAIN		=		debug.c \
						cub3d.c \
						img/get_new_img.c \
						end_process.c \

SRCS_DRAW		=		draw/put_pixel_on_img.c \
						draw/draw_ceiling.c \
						draw/draw_floor.c \
						draw/draw_pov.c \
						draw/draw_wall_line.c \

SRCS_RAYCASTING	=		raycasting/do_dda.c \
						raycasting/calculate_delta.c \
						raycasting/calculate_step.c \
						raycasting/calculate_perp_wall_dist.c \
						raycasting/get_hit_pos.c \
						raycasting/hit_dir.c \
						raycasting/get_texture_x.c \

SRCS_CAM_MOVE	=		camera_movement/read_key.c \
						camera_movement/move.c \
						camera_movement/rotate.c \
						camera_movement/starting_rotate.c \

SRCS_PARSING	=		parsing/parse_map.c \
						parsing/texture_parsing.c \
						parsing/check_line.c \
						parsing/check_map.c \
						parsing/error.c \
						parsing/free_parsing.c \
						parsing/is_char.c \
						parsing/start_coord.c \
						parsing/parsing_get_color.c \
						parsing/parsing_utils.c \
						xpm/get_texture.c \

SRCS_MAIN_BONUS			=	debug.c \
							cub3d_bonus.c \
							img/get_new_img.c \
							end_process.c \

SRCS_DRAW_BONUS			=	draw/put_pixel_on_img.c \
							draw/draw_ceiling.c \
							draw/draw_floor.c \
							draw/draw_pov.c \
							draw/draw_wall_line.c \

SRCS_RAYCASTING_BONUS	=	raycasting/do_dda.c \
							raycasting/calculate_delta.c \
							raycasting/calculate_step.c \
							raycasting/calculate_perp_wall_dist.c \
							raycasting/get_hit_pos.c \
							raycasting/hit_dir.c \
							raycasting/get_texture_x.c \

SRCS_CAM_MOVE_BONUS		=	camera_movement/read_key.c \
							camera_movement/move.c \
							camera_movement/rotate.c \
							camera_movement/starting_rotate.c \
							camera_movement/mouse_rotate_bonus.c \

SRCS_PARSING_BONUS		=	parsing/parse_map.c \
							parsing/texture_parsing.c \
							parsing/check_line.c \
							parsing/check_map.c \
							parsing/error.c \
							parsing/free_parsing.c \
							parsing/is_char.c \
							parsing/start_coord.c \
							parsing/parsing_get_color.c \
							parsing/parsing_utils.c \
							xpm/get_texture.c \

OBJS			=	$(addprefix ${OBJ_PATH}, ${SRCS_DRAW:.c=.o}) \
						$(addprefix ${OBJ_PATH}, ${SRCS_RAYCASTING:.c=.o}) \
						$(addprefix ${OBJ_PATH}, ${SRCS_CAM_MOVE:.c=.o}) \
						$(addprefix ${OBJ_PATH}, ${SRCS_PARSING:.c=.o}) \
						$(addprefix ${OBJ_PATH}, ${SRCS_MAIN:.c=.o}) \

OBJS_BONUS		=	$(addprefix ${OBJ_PATH}, ${SRCS_MAIN_BONUS:.c=.o}) \
					$(addprefix ${OBJ_PATH}, ${SRCS_DRAW_BONUS:.c=.o}) \
					$(addprefix ${OBJ_PATH}, ${SRCS_RAYCASTING_BONUS:.c=.o}) \
					$(addprefix ${OBJ_PATH}, ${SRCS_CAM_MOVE_BONUS:.c=.o}) \
					$(addprefix ${OBJ_PATH}, ${SRCS_PARSING_BONUS:.c=.o}) \



LIBFT_D			=	$(addprefix ${LIBFT_PATH}, ${LIBFT})

################################################################################
#                                 RULES                                        #
################################################################################
					
all:			${NAME}

bonus:			${BONUS}

${NAME}:		${MLX} ${LIBFT} ${OBJS} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@printf "${NEW}${YELLOW}${NAME}${RESET}${GREEN}${BOLD} Compiled\n${RESET}${GREEN}compiled with:${RESET} ${CC} ${CFLAGS}\n"

${BONUS}:		${MLX} ${LIBFT} ${OBJS_BONUS} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o ${BONUS} ${OBJS_BONUS} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@echo "${COLOUR_GREEN}${BONUS} Compiled${COLOUR_END}"

${OBJ_PATH}%.o:	${SRC_PATH}%.c ${HEADER_FILES}
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} ${HEADER} -c $< -o $@
		@printf "${NEW}${YELLOW} ${NAME} ${GREEN}Building: ${RESET}${CC} ${CFLAGS} ${ITALIC}${BOLD}$<${RESET}"

txt:			${TXT}

mlx_clone:
		git clone https://github.com/42Paris/minilibx-linux

compile:	mlx_clone ${LIBFT} ${OBJS}
		@printf "\n"

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
		@echo "-Ilibft/include\n-Iinclude/\n-Iminilibx-linux/\n-Wall -Werror -Wextra" > compile_flags.txt
		@echo "-I../libft/include\n-I../include/\n-I../minilibx-linux/\n-Wall -Werror -Wextra" > src/compile_flags.txt

clean:	
		@make -C ${LIBFT_PATH} clean --no-print-directory
		${RM} ${MLX_PATH}
		${RM}  ${OBJ_PATH}

fclean:		clean
		@make -C ${LIBFT_PATH} fclean --no-print-directory
		${RM} ${NAME} ${NAME_TEST} ${BONUS} ${LIBFT} ${MLX} ${SRC_PATH}${TXT} ${SRC_PATH}bonus/${TXT} ${TXT}

re:			fclean all

.PHONY:		all fclean clean re libft txt compile bonus
