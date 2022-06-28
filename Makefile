NAME	= pipex

NAME_BONUS	= pipex_bonus

HEADER	= 	includes/pipex.h		\
			libft2/includes/libft.h	\
			libft2/includes/gc.h

HEADER_BONUS = includes/pipex_bonus.h		\
			libft2/includes/libft.h			\
			libft2/includes/gc.h

LIBFT	= libft2

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

INCLUDES_BONUS= ${addprefix -I, ${sort ${dir ${HEADER_BONUS}}}}

SRCS	=	src/main.c					\
			src/p_parsing.c				\
			src/p_check.c				\
			src/e_exec.c

SRCS_BONUS	=	src_bonus/main.c			\

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC		= gcc

CFLAGS	= #-Wall -Werror -Wextra
# LIBFLAGS= -fsanitize=address -g3

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} libft2/libft2.a
		${CC}  ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ libft2/libft2.a

${NAME_BONUS}: ${OBJS_BONUS} libft2/libft2.a
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
