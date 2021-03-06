# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 15:48:35 by astridgault       #+#    #+#              #
#    Updated: 2021/07/30 13:36:04 by asgaulti@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	main.c ft_utils.c ft_error.c ft_parse_map.c ft_gnl.c ft_free.c \
			ft_utils_parsing.c ft_start_game.c ft_utils_mlx.c ft_draw_map.c \
			ft_actions.c ft_utils2.c ft_verif_txt.c 

PATH_SRCS = ./srcs/

OBJS	=	${addprefix ${PATH_SRCS}, ${SRCS:.c=.o}}

CC		=	clang
#CC		=	clang-9
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra
#-fsanitize=address -fsanitize=leak -g3
INCL	=	includes

MLX		= ./mlx_linux

MLX_LIB = ./mlx_linux/libmlx_Linux.a

.c.o:
			${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(MLX_LIB)
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME} ${MLX_LIB} \
			-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(MLX_LIB):
			make -C ${MLX} -j
			

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ${MLX}

fclean:		clean
			${RM} ${NAME}
			${RM} ${NAME} ${MLX_LIB}
					
re:			fclean
			$(MAKE) all -j

.PHONY:		all clean fclean re
