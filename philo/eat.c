/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:40:44 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/27 18:01:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf("%ld Philosopher %d has taken a fork\n", get_current_time(), philo->id);
	if (philo->nb_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	phtread_mutex_lock(&philo->l_fork);
	printf("%ld Philosopher %d has taken a fork\n", get_current_time(), philo->id);
	philo->eating = 1;
	printf("%ld Philosopher %d is eating\n", get_current_time(), philo->id);
	
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}
