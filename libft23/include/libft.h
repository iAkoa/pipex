/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:51:46 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/25 20:43:45 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "gc.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# define infile 1
# define outfile 1
# define heredoc 1
typedef struct s_command
{
	int		pfdin;
	int		pfdout;
	int		fd_infile;
	int		fd_outfile;
	int		argc;
	char	*cmd_path;
	char	*limiter;
	char	*here_doc;
	char	**envp;
	char	**cmd;
}			t_command;

typedef struct s_list
{
	t_command		*command;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

/* ft_check */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int character);
int		ft_tolower(int character);

/* ft_mem */
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *str, int value, size_t count);

/* ft_str */
char	*ft_strchr(const char *str, int searchedChar);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int searchedChar);
size_t	ft_strlen_charset(const char *str, char *charset);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

/* ft_calloc */
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

/* ft_put */
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd, int i);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putptr(unsigned long long n, int i);
int		ft_putnbr_usigned_fd(unsigned int n, int fd, int i);
int		ft_putnbr_base(unsigned int nbr, char *base, int i);

/* ft_lst */

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ft_gnl */
char	*get_next_line(int fd);

/* ft_maths */
double	ft_round(double value);
int		ft_colinterpolate(int color1, int color2, double purcent);

/* ft_atoi_itoa */
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa(int n);

#endif
