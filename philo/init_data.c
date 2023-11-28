/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:54:09 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/28 15:06:03 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_philo *philo, char **av)
{
	philo->nb_of_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->nb_times_to_eat = ft_atoi(av[5]);
	else
		philo->nb_times_to_eat = -1;
}

void	init_forks(pthread_mutex_t *forks, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_data(t_philo *philos, t_prog *prog, \
					pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while (i < philos->nb_of_philos)
	{
		init_args(&philos[i], av);
		philos[i].id = i + 1;
		philos[i].dead = &prog->dead_flag;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].write_lock = &prog->write_lock;
		philos[i].dead_lock = &prog->dead_lock;
		philos[i].meal_lock = &prog->meal_lock;
		philos[i].last_meal = get_timestamp();
		philos[i].start_time = get_timestamp();
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].nb_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_prog(t_prog *prog, t_philo *philos)
{
	prog->dead_flag = 0;
	prog->philos = philos;
	pthread_mutex_init(&prog->write_lock, NULL);
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
}
