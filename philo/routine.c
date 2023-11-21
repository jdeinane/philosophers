/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:07:58 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 12:13:36 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo *philo)
{
	while (1)
	{
		think(philo);
		get_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep(philo);
	}
}
