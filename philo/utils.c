/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:20:25 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/21 15:30:33 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	malloc_error(t_data *data)
{
	if (!data)
		return (MALLOC_ERROR);
}

u_int64_t	get_timestamp() //function to get the current timestamp in ms
{
	struct timeval	current_time;
	gettimeofday(&current_time, NULL);
	return (u_int64_t)(current_time.tv_sec * 1000) + (u_int16_t)(current_time.tv_sec / 1000);
}
