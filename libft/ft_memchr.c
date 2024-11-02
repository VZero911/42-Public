/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 23:39:52 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t size)
{
	while (size--)
	{
		if (*(unsigned char *)ptr++ == (unsigned char)ch)
			return ((void *)((unsigned char *)ptr - 1));
	}
	return (NULL);
}

/*int main(){
	const char *src="www.google.com";
	unsigned char c ='.';
	const char *ret;

	ret = ft_memchr(src, c, sizeof(src));
	printf("%s\n", ret);
	return 0;

}*/
