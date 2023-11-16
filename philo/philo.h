/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:45:07 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/16 16:46:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdint.h>
# include <string.h>

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

typedef struct	s_philo
{
	int					id;
	int					nb_meals;
	struct s_data		*data;
	t_state				state;
	phtread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	phthread_mutex_t	mut_state;
	phthread_mutex_t	mut_nb_meals;
	phthread_mutex_t	mut_last_meal; //time
	u_int64_t			last_meal; //time
}	t_philo;

#endif