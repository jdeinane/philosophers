/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:45:07 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 13:45:30 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdint.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define THINK "is thinking"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define DIED "died"
# define FORKS "has taken a fork"

typedef enum e_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5,
}	t_state;

typedef struct s_philo
{
	int					id;
	int					nb_meals_had;
	t_state				state;
	u_int64_t			last_meal_time;
	struct s_data		*data;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		mut_state;
	pthread_mutex_t		mut_nb_meals_had;
	pthread_mutex_t		mut_last_meal_time;
}	t_philo;

typedef struct s_data
{
	int					nb_philos;
	int					nb_meals;
	int					nb_full_p;
	bool				iterate;
	t_philo				*philos;
	u_int64_t			start_time;
	u_int64_t			eat_time;
	u_int64_t			die_time;
	u_int64_t			sleep_time;
	pthread_t			monit_all_alive;
	pthread_t			monit_all_full;
	pthread_t			*philo_ths;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mut_eat_t;
	pthread_mutex_t		mut_die_t;
	pthread_mutex_t		mut_sleep_t;
	pthread_mutex_t		mut_print;
	pthread_mutex_t		mut_nb_philos;
	pthread_mutex_t		mut_keep_iter;
	pthread_mutex_t		mut_start_time;
}	t_data;

#endif