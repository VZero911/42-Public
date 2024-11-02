/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 00:33:09 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*int	main(void)
{
	t_list	*list = NULL;
	int		size;
	
	ft_lstadd_back(&list, ft_lstnew("Premier élément"));
	ft_lstadd_back(&list, ft_lstnew("Deuxième élément"));
	ft_lstadd_back(&list, ft_lstnew("Troisième élément"));
	size = ft_lstsize(list);
	printf("%d", size);
	free(first);
	free(second);
	free(third);
	return 0;
}*/