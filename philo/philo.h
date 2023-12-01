/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:01:41 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/01 15:02:24 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define PHILO_MAX 200

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int					nb_of_philos;
	int					nb_times_to_eat;
	int					finished_meal;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					*forks_status;
	int					end;
	size_t				start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mut_end;
}	t_data;

typedef struct s_philo
{
	int					r_fork;
	int					l_fork;
	t_data				*philos;
	int					id;
	int					nb_meal;
	int					last_meal;
}	t_philo;

#endif