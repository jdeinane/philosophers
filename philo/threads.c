/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:29:39 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/29 17:19:11 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_threads(t_prog *prog, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	i = 0;
	if (pthread_create(&observer, NULL, &monitor, prog->philos) != 0)
		destroy_mutex("Error encountered while creating thread\n", prog, forks);
	while (i < prog->philos[0].nb_of_philos)
	{
		if (pthread_create(&prog->philos[i].thread, NULL, \
			&philo_routine, &prog->philos[i]) != 0)
			destroy_mutex("Error encountered while creating thread\n", \
			prog, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destroy_mutex("Error encountered while joining thread\n", prog, forks);
	while (i < prog->philos[0].nb_of_philos)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			destroy_mutex("Error encountered while joining thread\n", \
			prog, forks);
		i++;
	}
	return (0);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (1);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo[0].nb_of_philos)
		{
			if (*(philo[i].dead) == 1 || all_philo_ate(philo) == 1)
				break ;
			return (arg);
		}
	}
}
