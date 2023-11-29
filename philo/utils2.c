/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:17:00 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/29 17:20:00 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_timestamp() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	destroy_mutex(char *str, t_prog *prog, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&prog->write_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->dead_lock);
	while (i < prog->philos[0].nb_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
	}
}
