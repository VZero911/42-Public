/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:17 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/17 06:50:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_data t_data;
typedef pthread_mutex_t t_mutex;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}		t_tcode;

typedef	struct			s_philo
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long 				last_meal;
	pthread_t			thread_id;
	struct s_data		*data;
}		t_philo;

typedef struct			s_data
{
	int			nb_philo;
	int			time_death;
	int			time_eat;
	int			time_sleep;
	int			nb_eat;
	int			has_died;
	int			full;
	long 		first_timestamp;
	t_mutex		meal_check;
	t_mutex		writing;
	t_mutex		forks[250];
	t_philo		philos[250];
}		t_data;

int		write_error(char *str);
void    error_exit(const char *error);
int		error_main(int error);

long	timestamp(void);
void	precise_usleep(long time, t_data *data);
long	time_diff(long past, long present);
void	action_print(t_data *data, int id, char *string);

int		data_init(t_data *data, char **argv);

#endif