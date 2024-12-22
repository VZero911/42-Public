/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 23:57:10 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && (n > 1))
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/*int main(){
        char src[]="www.google.com";
        char c[]="www.google.co";
        int ret;

        ret = ft_strncmp(src, c, sizeof(src));
        printf("%d\n", ret);
        return 0;

}*/
