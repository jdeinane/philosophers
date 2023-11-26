/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:29:39 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/24 15:59:22 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_threads(t_philo *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < philos->nb_of_philos)
	{
		pthread_create(&threads[i], NULL, &philo_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < philos->nb_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!philo_dead)
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
}

void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	philo->dead = 1;
	pthread_mutex_unlock(philo->dead_lock);
}