/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 23:57:23 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		substr = ft_calloc(1, sizeof(char));
		return (substr);
	}
	if (ft_strlen(s) - start >= len)
		substr = ft_calloc(len + 1, sizeof(char));
	else
		substr = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i++] = s[start++];
	}
	substr[i] = 0;
	return (substr);
}

/*int	main()
{
 	char	v1[] = "hola";
 	char	*v2;
 	v2 = ft_substr(v1, 0, 10);
 	printf("%s / %s\n", v1, v2);
}*/
