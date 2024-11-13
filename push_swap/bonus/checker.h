/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 04:06:19 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

typedef struct s_stack
{
	int					value;
	int					index;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

long long		ft_atol(const char *nptr);
char			**ft_split(char const *s, char c);
char			**my_split(int argc, char **argv);
int				ft_atol_and_check(const char *nptr, int *error);
char			*get_next_line(int fd);
void			free_stack(t_stack **stack);
int				new_node(int nbr, t_stack **node);
int				add_to_list(t_stack **stack, int nbr);
int				initialize_stacks(t_stack **stack_a, t_stack **stack_b, char **spl);
void			free_split(char **split);
int				ft_strcmp(const char *s1, const char *s2);


void			pa(t_stack **stack_a, t_stack **stack_b, int print);
void			pb(t_stack **stack_a, t_stack **stack_b, int print);
void			rra(t_stack **stack_a, int print);
void			rrb(t_stack **stack_b, int print);
void			rrr(t_stack **p_a, t_stack **p_b, int print);
void			ra(t_stack **stack_a, int print);
void			rb(t_stack **stack_b, int print);
void			rr(t_stack **a, t_stack **b, int print);
void			sa(t_stack **stack_a, int print);
void			sb(t_stack **stack_b, int print);
void			ss(t_stack **stack_a, t_stack **stack_b, int print);

char			*get_next_line(int fd);
size_t			ft_strlen_gnl(const char *str);
char			*ft_strchr_gnl(const char *s, int c);
void			*ft_memcpy_gnl(void *dest, const void *src, size_t n);
char			*ft_strdup_gnl(const char *s);
char			*free_and_return(char **ptr);


#endif