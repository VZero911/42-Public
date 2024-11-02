/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 00:10:52 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*int	main(void)
{
	t_list	*first = ft_lstnew("Premier");
	t_list	*second = ft_lstnew("Deuxième");
	t_list	*third = ft_lstnew("Troisième");

	first->next = second;
	second->next = third;
	
	t_list	*last = ft_lstlast(first);
	
	printf("Le dernier élément de la liste est : %s\n", (char *)last->content);
	free(first);
	free(second);
	free(third);
	return (0);
}*/