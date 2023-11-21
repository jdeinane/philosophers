/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:20:07 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 14:44:34 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_philos, NULL);
	pthread_mutex_init(&data->iterate, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
}

void	init_philo_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->philos[i].mut_state, NULL);
		pthread_mutex_init(&data->philos[i].mut_nb_meals_had, NULL);
		pthread_mutex_init(&data->philos[i].mut_last_meal_time, NULL);
		i++;
	}
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
		malloc_error(data);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		malloc_error(data);
	while (i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].nb_meals_had = 0;
		data->philos[i].state = IDLE;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		data->philos[i].l_fork = &data->forks[(i + 1) % data->nb_philos];
		data->philos[i].r_fork = &data->forks[i];
		i++;
	}
}

void	init_data(t_data *data, int ac, char **av)
{
	data->nb_full_p = 0;
	data->iterate = true;
	data->nb_philos = ft_atoi(av[1]);
	data->die_time = (u_int64_t) ft_atoi(av[2]);
	data->eat_time = (u_int64_t) ft_atoi(av[3]);
	data->sleep_time = (u_int64_t) ft_atoi(av[4]);
	data->nb_meals = -1;
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
}
