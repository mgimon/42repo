/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:25:41 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/22 17:38:44 by mgimon-c         ###   ########.fr       */
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
		structure->philosophers[i].time_to_die = structure->time_to_die;	
		structure->philosophers[i].time_to_eat = structure->time_to_eat;
		structure->philosophers[i].time_to_sleep = structure->time_to_sleep;
		structure->philosophers[i].meals = 0;
		structure->philosophers[i].dead = 0;
		i++;
	}
	return (0);
}
