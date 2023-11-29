/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:40:44 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/29 17:21:24 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state("has taken a fork", philo, philo->id);
	if (philo->nb_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_state("has taken a fork", philo, philo->id);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	philo->eating = 1;
	print_state("is eating", philo, philo->id);
	ft_usleep(philo->time_to_eat);
	release_forks(philo);
}
