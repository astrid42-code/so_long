
NAME	=	so_long

SRCS	=	

PATH_SRCS = ./srcs/

OBJS	=	${addprefix ${PATH_SRCS}, ${SRCS:.c=.o}}

CC		=	clang9
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	Libft

LIBFT_LIB = Libft/libft.a

INCL	=	includes

LFLAGS = -L ${LIBFT}

MLX		= ./mlx_linux

MLX_LIB = ./mlx_linux/libmlx_Linux.a

.c.o:
			${CC} ${CFLAGS} -I${LIBFT} -I${INCL} -I${MLX} -g -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${LIBFT}
			make -C ${MLX}
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME} ${LIBFT_LIB} ${MLX_LIB} \
			-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ${LIBFT}
			make clean -C ${MLX}

fclean:		clean
			${RM} ${NAME} ${LIBFT_LIB} ${MLX_LIB}
					
re:			fclean all

.PHONY:		all clean fclean re