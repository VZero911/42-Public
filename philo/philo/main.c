/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:13 by jdumay            #+#    #+#             */
/*   Updated: 2025/01/28 18:19:01 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		error;

	if (argc != 5 && argc != 6)
		return (write_error("Wrong amount of arguments"));
	error = data_init(&data, argv);
	if (error)
		return (error_main(error));
	if (start_simulation(&data))
		return (write_error("Error creating the threads"));
	return (0);
}
