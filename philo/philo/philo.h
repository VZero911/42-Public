/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:17 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/08 19:11:20 by jdumay           ###   ########.fr       */
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
# include <limits.h>

typedef struct s_data t_data;
typedef pthread_mutex_t t_mutex;

typedef enum e_mutex_code
{
	LOCK	= 0,
	UNLOCK	= 1,
	INIT	= 2,
	DESTROY	= 3,
	CREATE	= 4,
	JOIN	= 5,
	DETACH	= 6,
}		t_code;

typedef struct s_fork
{
	t_mutex fork;
	int     fork_id;
}   	t_fork;

typedef struct s_philo
{
	int     	id;
	long    	meals_counter;
	long    	last_meal_time;
	bool		full;
	pthread_t	thread_id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data  	*data;
}   	t_philo;

typedef struct s_data
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_limit;
	long	start_simulation;
	bool	end_simulation;
	bool	ready_to_start;
	t_fork  *forks;
	t_philo *philos;
}		t_data;

void    parse_input(t_data *data, char **argv);
void    data_init(t_data *philo);
void    execute_philo(t_data *data);

void	mutex_handle(t_mutex *mutex, t_code code);
void	thread_handle(pthread_t *thread, t_code code,
			void *(*start_routine)(void *), void *arg);

void    error_exit(const char *error);
void	clean_data(t_data *data);

#endif