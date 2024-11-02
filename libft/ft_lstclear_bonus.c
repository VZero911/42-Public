/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 17:33:29 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	//free(content);
	(void)content;
}*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!*lst || !del)
		return ;
	next = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = next;
	ft_lstclear(lst, del);
}

/*int	main(void)
{
	t_list	*first = ft_lstnew("Premier élément");
	t_list	*second = ft_lstnew("Deuxième élément");
	t_list	*third = ft_lstnew("Troisième élément");

	first->next = second;
	second->next = third;

	printf("Avant suppression :\n");
	t_list *temp = first;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&first, del);
	if (first == NULL)
		printf("La liste a été complètement supprimée.\n");
	free(first);
	free(second);
	free(third);
	return (0);
}*/
