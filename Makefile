# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 10:36:26 by blevrel           #+#    #+#              #
#    Updated: 2022/05/19 10:43:35 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/so_long.c srcs/fill_matrix.c srcs/display_sprites.c srcs/event_management.c \
		srcs/open_window.c srcs/load_images.c srcs/check_map.c srcs/disp_error_msg.c \
		srcs/check_unknown_char.c srcs/end_prog.c srcs/init_struc.c

SRCSBON =	srcs_bonus/so_long_bonus.c srcs_bonus/fill_matrix_bonus.c \
			srcs_bonus/display_sprites_bonus.c srcs_bonus/event_management_bonus.c \
			srcs_bonus/open_window_bonus.c srcs_bonus/load_images_bonus.c \
			srcs_bonus/check_map_bonus.c srcs_bonus/disp_msg_bonus.c \
			srcs_bonus/check_unknown_char_bonus.c srcs_bonus/end_prog_bonus.c \
			srcs_bonus/init_struc_bonus.c srcs_bonus/ennemies_bonus.c \

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB =  -L mlx_linux -lmlx -lXext -lX11 -L libft -lft

HEAD = -I mlx_linux -I libft -I includes

HEADBON = -I mlx_linux -I libft -I includes_bonus

RM = rm -f

all: ${NAME}

clean:
	make clean -C libft
	make clean -C mlx_linux
	${RM}

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

bonus:
	make -C libft
	make -C mlx_linux
	${CC} ${FLAGS} ${SRCSBON} ${HEADBON} ${LIB} -o ${NAME}

${NAME}:
	make -C libft
	make -C mlx_linux
	${CC} ${FLAGS} ${SRCS} ${HEAD} ${LIB} -o ${NAME}
