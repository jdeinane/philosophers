/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:54:04 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/07 14:53:23 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_timestamp() - philo->last_meal >= time_to_die
		&& philo->eat == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	philo_died(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_of_philos)
	{
		if (check_death(&philos[i], philos[i].time_to_die))
		{
			print_status("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_meal(t_philo *philos)
{
	int	i;
	int	finished_eat;

	i = 0;
	finished_eat = 0;
	if (philos[0].nb_times_to_eat == -1)
		return (0);
	while (i < philos[0].nb_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].nb_times_to_eat)
			finished_eat++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eat == philos[0].nb_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
		if (philo_died(philos) == 1 || check_meal(philos) == 1)
			break ;
	return (arg);
}
