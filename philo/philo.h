/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:22:59 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/22 17:38:42 by mgimon-c         ###   ########.fr       */
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

typedef struct	s_philo
{
	pthread_t		thread_id;
	int				id;
	int				dead;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals;
}	t_philo;

typedef struct  s_struct
{
	long			start_time;
    long			number_of_philosophers;
    long			time_to_die;
    long			time_to_eat;
    long			time_to_sleep;
    long			n_must_eat;
    t_philo         *philosophers;
}   t_struct;

// process.c
int				philosophers(char **argv);

// init.c
int				init_info(t_struct *structure, char **argv);
int				init_philosophers(t_struct *structure);

// utils.c
long			get_time_now(void);
long			ft_atol(const char *str);

#endif
