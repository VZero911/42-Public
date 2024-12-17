/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:17 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/17 02:31:05 by marvin           ###   ########.fr       */
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

# define MODE 0
# define RST	"\033[0m"
# define RED	"\033[0,31m"
# define G		"\033[0,32m"
# define Y		"\033[0,33m"
# define B		"\033[0,34m"
# define M		"\033[0,35m"
# define C		"\033[0,36m"
# define W		"\033[0,37m"

typedef struct s_data t_data;
typedef pthread_mutex_t t_mutex;

typedef enum e_time_code
{
	SECOND		= 0,
	MILLISECOND	= 1,
	MICROSECOND	= 2,
}		t_tcode;

typedef enum e_philo_code
{
	EATING		= 0,
	SLEEPING	= 1,
	THINKING	= 2,
	RIGHT_FORK	= 3,
	LEFT_FORK	= 4,
	DIED		= 5,
}		t_phcode;

typedef enum e_mutex_code
{
	LOCK	= 0,
	UNLOCK	= 1,
	INIT	= 2,
	DESTROY	= 3,
	CREATE	= 4,
	JOIN	= 5,
	DETACH	= 6,
}		t_mcode;

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
	t_mutex		mutex_philo;
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
	bool	simulation_stop;
	bool	ready_to_start;
	t_mutex	mutex_data;
	t_mutex	mutex_write;
	t_fork  *forks;
	t_philo *philos;
}		t_data;

void    parse_input(t_data *data, char **argv);
void    data_init(t_data *philo);
void    execute_philo(t_data *data);

void	mutex_handle(t_mutex *mutex, t_mcode code);
void	thread_handle(pthread_t *thread, t_mcode code,
			void *(*start_routine)(void *), void *arg);

bool	simulation_finished(t_data *data);
bool	get_bool(t_mutex *mutex, bool *value);
long	get_long(t_mutex *mutex, long *value);
void	set_bool(t_mutex *mutex, bool *dest, bool value);
void	set_long(t_mutex *mutex, long *dest, long value);

long	get_time(t_tcode code);
void	precise_usleep(long usec, t_data *data);
void    error_exit(const char *error);
void	clean_data(t_data *data);
void    wait_all_threads(t_data *data);

void	write_status(t_phcode phcode, t_philo *philo, bool debug);

#endif