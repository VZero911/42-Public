/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/21 23:14:28 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src && *src != (char)c)
		src++;
	if (*src == (char)c)
		return ((char *)src);
	return (NULL);
}

/*int   main(){
		const char *src="www.facebook.com";
		const char c ='.';
		char *dest;

		dest = ft_strchr(src, c);
		printf("%s\n", dest);
		return 0;
}*/
