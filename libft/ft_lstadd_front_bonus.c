/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 00:32:47 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}
/*int	main(void)
{
	t_list	*first = ft_lstnew("Premier");
	t_list	*second = ft_lstnew("Deuxième");
	t_list	*third = ft_lstnew("Troisième");
	
	ft_lstadd_front(&first, second);
	ft_lstadd_front(&first, third);

	while(first)
	{
		printf("%s\n", (char *)first->content);
		first = first->next;
	}
	free(first);
	free(second);
	free(third);
	return (0);
}*/