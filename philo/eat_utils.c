/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:01 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 16:06:21 by jubaldo          ###   ########.fr       */
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