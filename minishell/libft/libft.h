/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:12:21 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 22:19:40 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>

# define BUFFER_SIZE 42
# define FD_MAX 1024
# define SPECIFIER	"cspdiuxX%"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum e_type
{
	SPECIFIER_CHAR		= 0,
	SPECIFIER_STRING		= 1,
	SPECIFIER_POINTER		= 2,
	SPECIFIER_INT		= 3,
	SPECIFIER_UNSIGNED		= 4,
	SPECIFIER_HEX_LOW		= 5,
	SPECIFIER_HEX_UP		= 6,
	SPECIFIER_PERCENTAGE		= 7,
	SPECIFIER_NONE		= -1
}	t_type;

typedef union u_var
{
	char			c;
	char			*s;
	void			*p;
	int				i;
	unsigned int	u;
	unsigned int	x;
}	t_var;

typedef struct s_data
{
	t_type	type;
	t_var	var;
	int		len;
}	t_struct;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *src, int c);
char	*ft_strrchr(const char *src, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putchar_fd(char c, int fd);
void	*ft_memchr(const void *ptr, int ch, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(const char *str, ...);

int		ft_printf_parsing(const char *str, va_list *args);
void	ft_get_data(const char **str, va_list *args, t_struct *data);
void	ft_printf_data(t_struct *data);
t_type	ft_get_type(char c);
t_var	ft_get_var(t_struct *data, va_list *args);

void	ft_printf_char(t_struct *data);
void	ft_printf_string(t_struct *data);
void	ft_printf_percentage(t_struct *data);
void	ft_printf_pointer(t_struct *data);
void	ft_printf_int(t_struct *data);

void	ft_printf_uint(t_struct *data);
void	ft_printf_hex_low(t_struct *data);
void	ft_printf_hex_up(t_struct *data);

void	ft_data_len(t_struct *data, int len);
int		ft_pointer_fd(unsigned long long ptr, char *base);
int		ft_putnum_fd(int nb, int fd);
int		ft_putunum_fd(unsigned int nb, int fd);

int		ft_putnbr_hex_low(unsigned int nb);
int		ft_putnbr_hex_up(unsigned int nb);

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_memcpy_gnl(void *dest, const void *src, size_t n);
char	*ft_strdup_gnl(const char *s);
char	*free_and_return(char **ptr);

void	ft_free_array(char **split);
void	ft_free_int_tab(int **tab, int size);
void	ft_free_split(char **split, size_t i);

char	*ft_strjoin_free(char *s1, char *s2);

#endif
