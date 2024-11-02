/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 00:32:44 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst)
		lst = &(*lst)->next;
	*lst = new;
}

/*int	main(void)
{
	t_list	*first = ft_lstnew("Premier");
	t_list	*second = ft_lstnew("Deuxième");
	t_list	*third = ft_lstnew("Troisième");
	
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);

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