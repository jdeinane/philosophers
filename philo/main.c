/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:31:08 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/09 17:29:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0 \
	|| ft_isdigit(av[1]) == 1)
		return (printf("Error: missing/too much philosophers\n"), 1);
	if (ft_atoi(av[2]) <= 0 || ft_isdigit(av[2]) == 1)
		return (printf("Error: time to die is not valid\n"), 1);
	if (ft_atoi(av[3]) <= 0 || ft_atoi(av[3]) > TIME_MAX \
	|| ft_isdigit(av[3]) == 1)
		return (printf("Error: time to eat is not valid\n"), 1);
	if (ft_atoi(av[4]) <= 0 || ft_atoi(av[4]) > TIME_MAX \
	|| ft_isdigit(av[4]) == 1)
		return (printf("Error: time to sleep is not valid\n"), 1);
	if (av[5] && (ft_atoi(av[5]) < 0 || ft_isdigit(av[5]) == 1))
		return (printf("Error: invalid number of meals for each philo\n"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac != 5 && ac != 6)
	{
		printf("Error: missing/too much arguments\n");
		return (1);
	}
	if (check_args(av) == 1)
		return (1);
	init_data(&data, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &data, forks, av);
	init_thread(&data, forks);
	destroy_all(NULL, &data, forks);
	return (0);
}
