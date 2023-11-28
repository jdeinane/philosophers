/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:32 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/28 15:03:44 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0 \
			|| ft_isdigit(av[1]) == 1)
		return (printf("Error: Invalid number of philosophers\n"), 1);
	if (ft_atoi(av[2]) <= 0 || ft_isdigit(av[2]) == 1)
		return (printf("Error: Invalid time to die\n"), 1);
	if (ft_atoi(av[3]) <= 0 || ft_isdigit(av[3]) == 1)
		return (printf("Error: Invalid meal time\n"), 1);
	if (ft_atoi(av[4]) <= 0 || ft_isdigit(av[4]) == 1)
		return (printf("Error: Invalid time to sleep\n"), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || ft_isdigit(av[5]) == 1))
		return (printf("Error: Invalid number of meals\n"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	forks[PHILO_MAX];
	t_philo			philos[PHILO_MAX];
	t_prog			prog;

	if (ac != 5 && ac != 6)
		return (printf("Error: Invalid number of arguments\n"));
	if (check_args(av) == 1)
		return (1);
	init_prog(&prog, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_data(philos, &prog, forks, av);
	philo_threads(&prog, forks);
	destroy_mutex(NULL, &prog, forks);
	return (0);
}
