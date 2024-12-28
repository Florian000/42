/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:45:32 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:39:25 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_sys_error(int status)
{
	if (0 == status)
		return (EXIT_SUCCESS);
	if (EINVAL == status)
		return (error_handler(EINVAL_ERROR), EXIT_FAILURE);
	else if (EDEADLK == status)
		return (error_handler(EDEADLK_ERROR), EXIT_FAILURE);
	else if (EPERM == status)
		return (error_handler(EPERM_ERROR), EXIT_FAILURE);
	else if (ENOMEM == status)
		return (error_handler(ENOMEN_ERROR), EXIT_FAILURE);
	else if (EBUSY == status)
		return (error_handler(EBUSY_ERROR), EXIT_FAILURE);
	else if (EAGAIN == status)
		return (error_handler(EAGAIN_ERROR), EXIT_FAILURE);
	else if (ESRCH == status)
		return (error_handler(ESRCH_ERROR), EXIT_FAILURE);
	else if (EFAULT == status)
		return (error_handler(EFAULT_ERROR), EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	safe_mutex(t_mtx *mutex, t_key k)
{
	if (LOCK == k)
		return (handle_sys_error(pthread_mutex_lock(mutex)));
	else if (UNLOCK == k)
		return (handle_sys_error(pthread_mutex_unlock(mutex)));
	else if (INIT == k)
		return (handle_sys_error(pthread_mutex_init(mutex, NULL)));
	else if (DESTROY == k)
		return (handle_sys_error(pthread_mutex_destroy(mutex)));
	return (EXIT_FAILURE);
}

int	safe_thread(pthread_t *t, void *(*f)(void *), void *d, t_key k)
{
	if (CREATE == k)
		return (handle_sys_error(pthread_create(t, NULL, f, d)));
	else if (JOIN == k)
		return (handle_sys_error(pthread_join(*t, NULL)));
	else if (DETACH == k)
		return (handle_sys_error(pthread_detach(*t)));
	return (EXIT_FAILURE);
}
