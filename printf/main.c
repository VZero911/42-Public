/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/27 01:22:56 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	len;
	int	a = 21464849;
	int	*p = &a;

	printf("%p\n", p);
	len = ft_printf("Adresse du pointeur : %p, l'entier = %d\n", p, a);
	ft_printf("%d\n", len);
}
