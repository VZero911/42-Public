/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/21 23:47:36 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i - 1]))
		i--;
	dest = ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, i + 1);
	return (dest);
}

/*int	main(void)
{
	char	dest[20] = "Hello";
	const char	src[] = " World!";
	size_t	size = sizeof(dest);
	size_t	result;

	printf("Avant ft_strlcat : '%s'\n", dest);
	result = ft_strlcat(dest, src, size);
	printf("Après ft_strlcat : '%s'\n", dest);
	printf("Longueur de la chaîne: %zu\n", result);

	return (0);
}*/
