NAME	= pipex

NAME_BONUS	= pipex_bonus

HEADER	= 	includes/pipex.h

HEADER_BONUS = includes/pipex_bonus.h

LIBFT	= libft2

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

INCLUDES_BONUS= ${addprefix -I, ${sort ${dir ${HEADER_BONUS}}}}

SRCS	=	src/main.c					\
			src/p_parsing.c				\
			src/p_check.c				\
			src/e_exec.c				\
			src/e_execve.c

SRCS_BONUS	=	src_bonus/main.c			\
				src_bonus/p_parsing.c		\
				src_bonus/p_check.c			\
				src_bonus/e_exec.c			\
				src_bonus/e_execve.c
OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

all: maker ${NAME}

%.o : %.c	${HEADER} ${HEADER_BONUS} Makefile
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} ${HEADER} Makefile
		${CC}  ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ libft2/libft2.a

${NAME_BONUS}: ${OBJS_BONUS} ${HEADER_BONUS} Makefile
		${CC}  ${CFLAGS} ${OBJS_BONUS} ${LIBFLAGS} ${INCLUDES_BONUS} -o $@ libft2/libft2.a

bonus: 	maker ${NAME_BONUS}

maker:
		${MAKE} -C ${LIBFT}

clean:
		rm -f ${OBJS}
		${MAKE} clean -C ${LIBFT}

clean_bonus:
		rm -f ${OBJS_BONUS}
		${MAKE} clean -C ${LIBFT}

fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}

fclean_bonus:	clean_bonus
		rm -f ${NAME_BONUS}
		${MAKE} fclean -C ${LIBFT}

re:		fclean all
re_bonus: fclean_bonus bonus
.PHONY: all bonus clean fclean re maker clean_bonus fclean_bonus
