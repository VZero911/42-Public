/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 04:00:59 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long	ft_atol(const char *nptr)
{
	long long		nbr;
	int				signe;
	int				i;
	char			*str;

	i = 0;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signe = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe = -signe;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - 48);
	return (nbr * signe);
}

static int	count_nbr(long long nbr)
{
	int					count;
	unsigned long long	n;

	count = 1;
	if (nbr < 0)
	{
		n = -(unsigned long long)nbr;
		++count;
	}
	else
		n = nbr;
	while (n >= 10)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static char	*ft_ltoa(long long n)
{
	char				*str;
	int					i;
	unsigned long long	t;

	i = count_nbr(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		t = -(unsigned long long)n;
	else
		t = n;
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = (t % 10) + '0';
		t /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}

int	ft_atol_and_check(const char *nptr, int *error)
{
	long long	result;
	char		*tmp;

	*error = 0;
	result = ft_atol(nptr);
	tmp = ft_ltoa(ft_atol(nptr));
	if (result > INT_MAX || result < INT_MIN || !ft_strcmp(tmp, nptr))
	{
		free(tmp);
		*error = 1;
		return (0);
	}
	free(tmp);
	return ((int)result);
}
