/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/07 05:19:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data  data;

	if (argc == 5 || argc == 6)
	{
		parse_input(&data, argv);
		data_init(&data);
		execute_philo();
		// clean_data();
	}
	else
		error_exit("Wrong Input");
}
