/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:17:25 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 12:22:11 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	if (ac == 7)
	{
		init_data(*data, av);
		init_philos(&data);
		create_philos(&data);
		monitor_philos(&data);
		while (i++ < data->nb_philos)
			pthread_join(data.philo_ths[i], NULL);
	}
	else
		printf("Wrong arguments");
	return (0);
}
