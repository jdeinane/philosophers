/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:45:07 by jubaldo           #+#    #+#             */
/*   Updated: 2023/11/28 13:21:12 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define PHILO_MAX 200

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int					id;
	int					*dead;
	int					eating;
	int					meals_eaten;
	int					nb_of_philos;
	int					nb_times_to_eat;
	size_t				last_meal;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start_time;
	pthread_t			thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
}	t_philo;

typedef struct s_prog
{
	int					dead_flag;
	t_philo				*philos;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
}	t_prog;

// data initialization
void	init_args(t_philo *philo, char **av);
void	init_forks(pthread_mutex_t *forks, int nb_philo);
void	init_data(t_philo *philos, t_prog *prog, pthread_mutex_t *forks, char **av);
void	init_prog(t_prog *prog, t_philo *philos);

// threads creation
int		philo_threads(t_prog *prog, pthread_mutex_t *forks);
int		dead_loop(t_philo *philo);
void	*monitor(void *arg);

// routine
void	*philo_routine(void *arg);

// philosophers actions
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// check philo state
int		all_philo_ate(t_philo *philos);
int		philo_died(t_philo *philo, size_t time_to_die);
int		is_philo_dead(t_philo *philos);

// utils
int		ft_atoi(const char *str);
int		ft_isdigit(char *str);
int		ft_usleep(size_t ms);
int	ft_strlen(char *str);
void	destroy_mutex(char *str, t_prog *prog, pthread_mutex_t *forks);
size_t	get_timestamp(void);

// main
int		check_args(char **av);
int		main(int ac, char **av);

#endif