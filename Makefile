NAME	= pipex
HEADER	= 	pipex.h \
			libft/libft.h

LIBFT	= Libft

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}
SRCS	=	main.c

OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LIBFLAGS=

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} libft/libft.a
		${CC} ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ Libft/libft.a

maker:
		${MAKE} -C ${LIBFT}
clean:
		rm -f ${OBJS}
		${MAKE} clean -C ${LIBFT}
fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}
re:		fclean all
.PHONY: all clean fclean re maker
