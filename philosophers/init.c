/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:25:41 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/02 21:39:22 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	invalid_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_empty(argv[i]))
			return (1);
		if (invalid_integer(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	init_mutexes(t_struct *structure)
{
	int	i;
	int	n;

	i = 0;
	n = structure->number_of_philosophers;
	structure->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (structure->forks == NULL)
		return (1);
	while (i < n)
	{
		if (pthread_mutex_init(&structure->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

// if the user does not specify n_must_eat, it is set to -1
int	init_info(t_struct *structure, char **argv)
{
	int				args_valid;

	args_valid = check_args(argv);
	if (args_valid > 0)
		return (args_valid);
	structure->number_of_philosophers = ft_atol(argv[1]);
	structure->time_to_die = ft_atol(argv[2]);
	structure->time_to_eat = ft_atol(argv[3]);
	structure->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		structure->n_must_eat = ft_atol(argv[5]);
	else	
		structure->n_must_eat = -1;
	structure->start_time = get_time_now();
	if (init_mutexes(structure) != 0)
		return (1);	
	structure->one_dead = 0;
	return (args_valid);
}

int	init_philosophers(t_struct *structure)
{
	int	i;

	i = 0;
	structure->philosophers = malloc(sizeof(t_philo) * structure->number_of_philosophers);
	if (structure->philosophers == NULL)
		return (1);
	while (i < structure->number_of_philosophers)
	{
		structure->philosophers[i].id = i + 1;
		structure->philosophers[i].meals = 0;
	/*	structure->philosophers[i].dead = 0;*/
		structure->philosophers[i].structure = structure;
		structure->philosophers[i].last_meal_time = get_time_now();
		structure->philosophers[i].left = structure->philosophers[i].id - 1;
		if (structure->number_of_philosophers != 1)
			structure->philosophers[i].right = structure->philosophers[i].id % structure->number_of_philosophers;
		i++;
	}
	return (0);
}
