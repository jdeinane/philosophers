/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:04:03 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/08 17:48:11 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < ms)
		usleep(500);
	return (0);
}

size_t	get_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error: failed to get time of day.\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
