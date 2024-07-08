/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:22:59 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/08 22:01:45 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				left;
	int				right;
	long			last_meal_time;
	long			meals;
	struct s_struct	*structure;
}	t_philo;

typedef struct s_struct
{
	pthread_mutex_t	mutex;
	int				one_dead_or_done;
	long			start_time;
	long			number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_must_eat;
	pthread_mutex_t	*forks;
	t_philo			*philosophers;
}	t_struct;

// tasks.c
int				philosopher_takes_forks(t_philo *philosopher);
int				philosopher_eats(t_philo *philosopher);
int				philosopher_sleeps(t_philo *philosopher);

// process.c
void			*start_routine(void *philo_pointer);
int				philosophers(char **argv);

// init.c
int				init_info(t_struct *structure, char **argv);
int				init_philosophers(t_struct *structure);

// utils.c
void			free_and_destroy(t_struct *structure);
int				is_empty(char *str);
long			get_time_now(t_struct *structure);
long			ft_atol(const char *str);
void			waiter(t_philo *philosopher, long time);

// utils_2.c
int				run_threads(t_struct *structure);
int				philosopher_dead(t_philo *philosopher);
void			stop_setter(t_struct *structure);

#endif
