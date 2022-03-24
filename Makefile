NAME	= pipex

NAME_BONUS	= pipex_bonus

HEADER	= 	includes/pipex.h		\
			libft2/includes/libft.h	\
			libft2/includes/gc.h

HEADER_BONUS = includes/pipex_bonus.h		\
			libft2/includes/libft.h			\
			libft2/includes/gc.h

LIBFT	= libft

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}
SRCS	=	src/main.c			\
			src/ft_free_error.c	\
			src/ft_check.c		\
			src/ft_operation.c	\
			src/ft_init_ptr.c

SRCS_BONUS	=	src_bonus/main.c			\
			src_bonus/ft_free_error.c		\
			src_bonus/ft_check.c			\
			src_bonus/ft_operation.c		\
			src_bonus/ft_init_ptr.c			\

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra
# LIBFLAGS= -fsanitize=address -g3

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} libft/libft.a
		${CC}  ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ Libft/libft.a

${NAME_BONUS}: ${OBJS_BONUS} libft/libft.a
		${CC}  ${CFLAGS} ${OBJS_BONUS} ${LIBFLAGS} ${INCLUDES} -o $@ Libft/libft.a

bonus: 	maker ${NAME_BONUS}

maker:
		${MAKE} -C ${LIBFT}

clean:
		rm -f ${OBJS} ${OBJS_BONUS}
		${MAKE} clean -C ${LIBFT}

fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}

re:		fclean all
.PHONY: all bonus clean fclean re maker
