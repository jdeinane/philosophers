/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:29:52 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/27 17:07:20 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop)
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
}
