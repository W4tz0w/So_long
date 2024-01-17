/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:10:20 by egiovann          #+#    #+#             */
/*   Updated: 2024/01/11 00:02:14 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_bzero(void *s, int n);
void	*ft_calloc(size_t nitems, size_t size);
int		ft_argument_c(char c);
int		ft_arguments_d_i(int c);
int		ft_argument_p(unsigned long address);
int		ft_argument_percent(void);
int		ft_argument_s(char *str);
int		ft_argument_u(unsigned int nbr);
int		ft_arguments_x(unsigned int nbr, char type);
char	ft_decimal_converter_to_hex(char digit, char type);
int		ft_decimal_length(long int nbr);
void	ft_free_ptr(char **ptr);
int		ft_hex_length(unsigned long nbr);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isalpha(char c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isdigit(char c);
int		ft_isupper(int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *dest, int c, size_t len);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(char *str, char *to_find, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dest, const void *src, size_t len);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_print_reversed_str(char *str);
int		ft_printf(const char *str, ...);
int		gnl_strlen(const char *s);
int		gnl_strchr(const char *s, char c);
char	*gnl_calloc(int count, int size);
char	*gnl_join_n_free(char *stash, char *buff);
char	*gnl_fill_stash(char *stash, int fd);
char	*gnl_extract_line(char *stash, int pos);
char	*gnl_cpy_leftovers(char *stash, char *line, int pos);
char	*get_next_line(int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);

# endif
#endif
