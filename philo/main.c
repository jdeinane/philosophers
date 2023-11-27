/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:32 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/27 17:45:00 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1] <= 0) || ft_isdigit(av[1]) == 1)
		printf("Error: Invalid number of philosophers\n");
	if (ft_atoi(av[2]) <= 0 || ft_isdigit(av[2]) == 1)
		printf("Error: Invalid time to die\n");
	if (ft_atoi(av[3]) <= 0 || ft_isdigit(av[3]) == 1)
		printf("Error: Invalid meal time\n");
	if (ft_atoi(av[4]) <= 0 || ft_isdigit(av[4]) == 1)
		printf("Error: Invalid time to sleep\n");
	if (av[5] && (ft_atoi(av[5]) <= 0 || ft_isdigit(av[5]) == 1))
		printf("Error: Invalid number of meals\n");
	return (0);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	forks[PHILO_MAX];
	t_philo			philos[PHILO_MAX];
	t_prog			prog;

	if (check_args(av) == 1)
		return (1);
	if (ac == 5 || ac == 6)
	{
		init_prog(&prog, philos);
		init_forks(&prog, ft_atoi(av[1]));
		init_data(philos, &prog, forks, av);
		philo_threads(&prog, forks);
		destroy_mutex(NULL, &prog, forks);
	}
	else
		printf("Error: Wrong number of arguments\n");
	return (0);
}
