/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 04:28:34 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 04:28:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_thread_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN && code == CREATE)
		error_exit("Not enough resources to create another thread");
	else if (status == EINVAL && code == JOIN)
		error_exit("Thread is not a joinable thread or already joined");
	else if (status == ESRCH && code == JOIN)
		error_exit("No thread with the ID could be found");
	else if (status == EDEADLK)
		error_exit("Deadlock detected while joining thread");
	else if (status == EINVAL && code == DETACH)
		error_exit("Thread is not joinable or already detached");
	else
		error_exit("Unknown thread error occurred!");
}

static void	handle_mutex_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (code == LOCK || code == UNLOCK))
		error_exit("The value specified by mutex is invalid");
	else if (status == EINVAL && code == INIT)
		error_exit("The value specified by attr is invalid");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread blocked waiting for mutex");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory to create another mutex");
	else if (status == EBUSY)
		error_exit("Mutex is locked");
	else
		error_exit("Unknown mutex error occurred!");
}

void	thread_handle(pthread_t *thread, t_code code,
	void *(*start_routine)(void *), void *arg)
{
	if (code == CREATE)
		handle_thread_error(pthread_create(thread, NULL, start_routine, arg),
			code);
	else if (code == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		handle_thread_error(pthread_detach(*thread), code);
	else
		error_exit("Wrong code for thread operation!");
}

void	mutex_handle(t_mutex *mutex, t_code code)
{
	if (code == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		handle_mutex_error(pthread_mutex_unlock(mutex), code);
	else
		error_exit("Wrong code for mutex!");
}