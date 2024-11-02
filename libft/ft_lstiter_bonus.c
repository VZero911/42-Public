/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 00:34:31 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*int	main(void)
{
	t_list	*first = ft_lstnew("Premier");
	t_list	*second = ft_lstnew("Deuxième");
	t_list	*third = ft_lstnew("Troisième");
	
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);

	ft_lstiter(first, print_content);
	free(first);
	free(second);
	free(third);
	return (0);
}*/