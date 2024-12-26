/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/26 20:27:41 by jdumay           ###   ########.fr       */
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
	start_simulation(&data);
	return (0);
}
