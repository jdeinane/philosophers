/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:08:07 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/08 14:58:02 by jubaldo          ###   ########.fr       */
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

void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks,
		char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eat = 0;
		philos[i].meals_eaten = 0;
		init_args(&philos[i], av);
		philos[i].start_time = get_timestamp();
		philos[i].last_meal = get_timestamp();
		philos[i].write = &data->write;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].dead = &data->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].nb_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_data(t_data *data, t_philo *philos)
{
	data->dead_flag = 0;
	data->philos = philos;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
}

int	init_thread(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, data->philos) != 0)
		destroy_all("threads creation error", data, forks);
	i = 0;
	while (i < data->philos[0].nb_of_philos)
	{
		if (pthread_create(&data->philos[i].threads, NULL, &philo_routine,
				&data->philos[i]) != 0)
			destroy_all("threads creation error", data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destroy_all("threads join error", data, forks);
	while (i < data->philos[0].nb_of_philos)
	{
		if (pthread_join(data->philos[i].threads, NULL) != 0)
			destroy_all("threads join error", data, forks);
		i++;
	}
	return (0);
}
