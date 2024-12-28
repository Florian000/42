/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:02:07 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:39:16 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include "error.h"

# define MAX_PHILO 200

typedef enum e_time_code
{
	SECONDS,
	MILLISECOND,
	MICROSECOND,
}		t_time_code;

typedef enum e_key
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_key;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_status;

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
	bool		is_init;
}				t_fork;

typedef struct s_philo
{
	int				id;
	bool			full;
	long			meals;
	long			last_meal;
	pthread_t		thread_id;
	t_fork			*first;
	t_fork			*second;
	t_mtx			mtx_philo;
	bool			is_init;
	t_table			*table;
}				t_philo;

struct	s_table
{
	long				t_die;
	long				t_eat;
	long				t_sleep;
	long				n_meals;
	long				n_philo;
	long				start;
	bool				end;
	bool				sync;
	long				n_running;
	pthread_t			monitor;
	t_fork				*forks;
	t_philo				*philos;
	t_mtx				table_mutex;
	bool				is_table_init;
	t_mtx				write_mutex;
	bool				is_write_init;
};

//utils functions
void	error_handler(const char *error);
long	ft_atol(char *str);
void	write_status(t_status status, t_philo *philo);
void	precise_usleep(long usec, t_table *table);
long	gettime(int time_code);

//Parsing inputs
int		parser(int ac, char **av, t_table *table);

//SAFE FUNCTIONS
int		handle_sys_error(int status);
int		safe_thread(pthread_t *t, void *(*f)(void *), void *d, t_key k);
int		safe_mutex(t_mtx *mutex, t_key k);

//Clean table
void	set_init_flags(t_table *table);
void	clean(t_table *table);

//init dinner values
int		init_dinner(t_table *table);
int		init_threads(t_table *table);
void	*dinner_run(void *data);
void	*dinner_alone(void *arg);

//Getters / setters
void	set_bool(t_mtx	*mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
long	get_long(t_mtx *mutex, long *value);
void	set_long(t_mtx *mutex, long *dest, long value);
void	increase_long(t_mtx *mutex, long *value);
bool	simulation_finished(t_table *table);

//Monitor function
void	*monitor(void *data);
int		dinner_start(t_table *table);
void	de_synchronize_philos(t_philo *philo);
void	wait_all_threads(t_table *table);
void	thinking(t_philo *philo);
bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr);
bool	philo_died(t_philo *philo);
#endif
