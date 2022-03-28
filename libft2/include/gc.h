/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:41:26 by pat               #+#    #+#             */
/*   Updated: 2022/03/25 16:12:06 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H
# include "libft.h"

typedef struct s_track
{
	void			**address;
	void			***address_split;
	struct s_track	*next;
	struct s_track	*prev;
}			t_track;

/* lst */
struct s_list	*gc_lstnew(t_track **track, void *content);

/* gc */
void	gc_lstadd_front(t_track **alst, t_track *new);
void	gc_lstclear(t_track **lst, void (*del)(void*));
void	gc_lstdelone(t_track *lst, void (*del)(void*));
void	gc_add_mal(t_track **track, void **address);
void	gc_free_all(t_track **track);
void	gc_free_malloc(t_track **track, void **del);
void	gc_free_malloc_split(t_track **track, void ***del);
void	gc_error(t_track **track);
t_track	*gc_tracknew(void **address);

/* malloc */
void	*gc_calloc(size_t count, size_t size, t_track **track);

/* str */
char	**gc_split(t_track **track, char const *s, char c);
char	*gc_strdup(t_track **track, const char *src);
char	*gc_strjoin(t_track **track, char const *s1, char const *s2);
char	*gc_substr(t_track **track, const char *s,
			unsigned int start, size_t len);
char	*gc_strtrim(t_track **track, const char *s1, const char *set);

/* itoa */
char	*gc_itoa(t_track **track, int n);

/* gnl */
char	*gc_get_next_line(t_track **track, int fd);

#endif
