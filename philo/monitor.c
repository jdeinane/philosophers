/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:09:47 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 12:17:13 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_philos(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		usleep(1000);
		while (i++ < data->nb_philos)
		{
			if (data->philos[i].state == DEAD)
			{
				printf("Philosopher %d died\n", data->philos[i].id);
				break ;
			}
		}
	}
	if (i == data->nb_philos)
		return ;
}
