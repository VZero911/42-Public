/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/17 06:49:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data  data;
	int		error;

	if (argc != 5 && argc != 6)
		return (write_error("Wrong amount of arguments"));
	if ((error = data_init(&data, argv)))
		return (error_main(error));
	// start_simulation(&data);
	return (0);
}
