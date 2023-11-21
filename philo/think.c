/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:29:14 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 15:38:52 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philosopher)
{
	pthread_mutex_lock(&(philosopher->mut_state));
	philosopher->state = THINKING;
	pthread_mutex_unlock(&(philosopher->mut_state));
	
}