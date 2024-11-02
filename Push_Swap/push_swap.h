/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 20:52:01 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				main(int argc, char **argv);
char			**my_split(char *str, char separator);

void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
int				error_free(t_stack_node **a, char **argv, bool flag_argc_2);
int				error_repetition(t_stack_node *a, int nbr);
int				error_syntax(char *str_nbr);

void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void			new_node(t_stack_node **stack, int nbr);
t_stack_node	*ft_last_node(t_stack_node *node);
bool			stack_sorted(t_stack_node *stack);
long			ft_atol(const char *str);

int				stack_len(t_stack_node *stack);

void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **b, t_stack_node **a);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);

#endif
