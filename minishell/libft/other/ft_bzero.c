/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/22 17:06:36 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	char		*str;
	size_t		i;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = 0;
}

/*int main(){
	char str[9]= "Jesuisla";
	ft_bzero(str, sizeof(str));
	printf("%s\n", str);
	return (0);
}*/
