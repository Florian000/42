/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:02:29 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/08 21:48:40 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//man erno for mutex and thread manipulation
# define EAGAIN_ERROR "Resource temporarily unavailable\n"
# define EBUSY_ERROR "Device or resource busy\n"
# define EDEADLK_ERROR "Resource deadlock avoided\n"
# define EINVAL_ERROR "Invalid argument\n"
# define ENOMEN_ERROR "Not enough space/cannot allocate memory\n"
# define EPERM_ERROR "Operation not permitted\n"
# define ESRCH_ERROR "No such process\n"
# define EFAULT_ERROR "Bad address\n"
# define ARGS_WRONG "Wrong number of arguments.\n\
usage :\n\
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>\
[number_of_times_each_philosopher_must_eat]\n"
# define PHILO_WRONG "Wrong Number of philo : must be between 1 and 200\n"
# define DIE_WRONG "Wrong time to die : must between 60 and INTMAX\n"
# define EAT_WRONG "Wrong time to eat : must between 60 and INTMAX\n"
# define SLEEP_WRONG "Wrong time to sleep : must between 60 and INTMAX\n"
# define MEALS_WRONG "Wrong number of meals : must between 60 and INTMAX\n"

#endif
