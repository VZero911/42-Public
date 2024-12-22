/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 21:51:48 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	while (i >= 0)
	{
		if (src[i] == (char)c)
			return ((char *)(src + i));
		i--;
	}
	return (NULL);
}

/*int   main(void)
{
	const   char *c = "com.facebook.com";
	const   char ch = '.';
	char    *ret;

	ret = ft_strrchr(c, ch);
	printf("%s\n", ret);
	return 0;
}*/
