/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/19 01:09:40 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (*big && len--)
	{
		i = 0;
		while (*(big + i) == *(little + i) && *(little + i) && i <= len)
		{
			if (!*(little + i + 1))
				return ((char *)big);
			i++;
		}
		big++;
	}
	return (NULL);
}

/*int main()
{
	const char *s1="jesuisla";
	const char *s2="suis";
	char *ptr;

	ptr = ft_strnstr(s1, s2, sizeof(s1));
	printf("%s\n", ptr);
	return 0;
}*/
