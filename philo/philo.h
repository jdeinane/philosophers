/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:03:45 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/07 14:56:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 200

typedef struct s_philo
{
	int				id;
	int				*dead;
	int				eat;
	int				meals_eaten;
	int				nb_of_philos;
	int				nb_times_to_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			last_meal;
	pthread_t		threads;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
}	t_philo;

typedef struct s_data
{
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write;
}	t_data;

// init data
void	init_args(t_philo *philo, char **av);
void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks, char **av);
void	init_forks(pthread_mutex_t *forks, int philos);
void	init_data(t_data *data, t_philo *philos);
int		init_thread(t_data *data, pthread_mutex_t *forks);


// philo routine
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	*philo_routine(void *arg);
int		dead_loop(t_philo *philo);


// check philo state
int		check_death(t_philo *philo, size_t time_to_die);
int		philo_died(t_philo *philos);
int		check_meal(t_philo *philos);
void	*monitor(void *arg);

// main
int	check_args(char **av);
int	main(int ac, char **av);

// utils
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_isdigit(char *str);
int		ft_usleep(size_t ms);
void	destroy_all(char *str, t_data *data, pthread_mutex_t *forks);
void	print_status(char *str, t_philo *philo, int id);
size_t	get_timestamp(void);

#endif