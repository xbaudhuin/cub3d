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
					libft/include/ft_printf.h \
					libft/include/get_next_line.h \
					libft/include/libft.h \

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SRC_PATH		=	src/

OBJ_PATH		=	obj/

CC				=	cc

RM				=	rm -rf

AR				=	ar rcs

SRCS_MAIN		=	main.c \

OBJS			=	$(addprefix ${OBJ_PATH}, ${SRCS_MAIN:.c=.o}) \

LIBFT_D			=	$(addprefix ${LIBFT_PATH}, ${LIBFT})

SRCS_TEST		=	test_leo.c \

OBJS_TEST		=	$(addprefix ${OBJ_PATH}, ${SRCS_TEST:.c=.o}) \
################################################################################
#                                 RULES                                        #
################################################################################
					
all:			${NAME}

bonus:			${BONUS}

${NAME}:		${MLX} ${LIBFT} ${OBJS} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@echo "${COLOUR_GREEN}${NAME} Compiled${COLOUR_END}"

test.exe:		${MLX} ${LIBFT} ${OBJS_TEST} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o test.exe ${OBJS_TEST} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@echo "${lsCOLOUR_GREEN}test.exe Compiled${COLOUR_END}"

${BONUS}:		${MLX} ${LIBFT} ${OBJS} ${TXT} ${HEADER_FILES}
		@${CC} ${CFLAGS} -o ${BONUS} ${OBJS} ${HEADER} ${MATH_FLAG} ${MLX_FLAG} ${LIBFT} ${MLX}
		@echo "${COLOUR_GREEN}${BONUS} Compiled${COLOUR_END}"

${OBJ_PATH}%.o:	${SRC_PATH}%.c
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} ${HEADER} -c $< -o $@

${LIBFT}:
		@make -C ${LIBFT_PATH} DEBUG=$(DEBUG) --no-print-directory
		@cp ${LIBFT_PATH}${LIBFT} .
		@echo "$(COLOUR_GREEN)Libft Compiled${COLOUR_END}"

${MLX}:
		${RM} ${MLX_PATH}
		git clone https://github.com/42Paris/minilibx-linux
		make -C ${MLX_PATH}
		cp ${MLX_PATH}${MLX} .
		@echo "$(COLOUR_GREEN)MLX compiled${COLOUR_END}"

${TXT}:
		@echo "-Ilibft/include\n-Iinclude/" > compile_flags.txt
		@echo "-I../libft/include\n-I../include/" > src/compile_flags.txt

clean:
		make -C ${LIBFT_PATH} clean --no-print-directory
		make -C ${MLX_PATH} clean --no-print-directory
		${RM}  ${OBJ_PATH}

fclean:		clean
		make -C ${LIBFT_PATH} fclean --no-print-directory
		${RM} ${MLX_PATH}
		${RM} ${NAME} ${NAME_TEST} ${BONUS} ${LIBFT} ${MLX} ${SRC_PATH}${TXT} ${SRC_PATH}bonus/${TXT} ${TXT}

re:			fclean all

.PHONY:		all fclean clean re libft


