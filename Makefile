# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 15:48:35 by astridgault       #+#    #+#              #
#    Updated: 2021/06/13 14:59:32 by asgaulti@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	main.c ft_utils.c ft_error.c ft_parse_map.c ft_gnl.c ft_free.c \
			ft_utils_parsing.c ft_start_game.c ft_utils_mlx.c 

PATH_SRCS = ./srcs/

OBJS	=	${addprefix ${PATH_SRCS}, ${SRCS:.c=.o}}

CC		=	clang
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

INCL	=	includes

MLX		= ./mlx_linux

MLX_LIB = ./mlx_linux/libmlx_Linux.a

.c.o:
			#${CC} ${CFLAGS} -I${INCL} -g -c $< -o ${<:.c=.o}
			${CC} ${CFLAGS} -I${INCL} -I${MLX} -g -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${MLX}
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME} ${MLX_LIB} \
			-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ${MLX}

fclean:		clean
			${RM} ${NAME}
			${RM} ${NAME} ${MLX_LIB}
					
re:			fclean all

.PHONY:		all clean fclean re