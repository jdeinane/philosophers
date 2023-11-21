/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:11:32 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 15:30:41 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->l_fork);
	pthread_mutex_lock(philosopher->r_fork);
}

void	release_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->l_fork);
	pthread_mutex_unlock(philosopher->r_fork);
}

void	update_meal(t_philo *philosopher)
{
	pthread_mutex_lock(&(philosopher->mut_last_meal_time));
	philosopher->last_meal_time = get_timestamp();
	pthread_mutex_unlock(&(philosopher->mut_last_meal_time));
	pthread_mutex_lock(&(philosopher->mut_nb_meals_had));
	philosopher->nb_meals_had++;
	pthread_mutex_unlock(&(philosopher->mut_nb_meals_had));
	usleep(philosopher->data->eat_time * 1000);
}

void	eat(t_philo *philosopher)
{
	pthread_mutex_lock(&(philosopher->mut_state));
	philosopher->state = EATING;
	pthread_mutex_unlock(&(philosopher->mut_state));
	take_forks(philosopher);
	release_forks(philosopher);
	udapte_meal(philosopher);
}