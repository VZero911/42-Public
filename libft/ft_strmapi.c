/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/21 17:47:34 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	to_uppercase(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s[++i])
		result[i] = (*f)(i, s[i]);
	result[i] = 0;
	return (result);
}

/*int	main(void)
{
	char	str[] = "hello world!";
	char	*new_str;

	printf("Chaîne originale : %s\n", str);
	new_str = ft_strmapi(str, to_uppercase);
	if (!new_str)
	{
		printf("Erreur\n");
		return (1);
	}
	printf("Nouvelle chaîne : %s\n", new_str);
	free(new_str);

	return (0);
}*/
