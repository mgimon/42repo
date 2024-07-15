/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:24:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/15 18:31:19 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	when_forks_taken(t_philo *philosopher)
{
	if (philosopher_dead(philosopher))
		return (pthread_mutex_unlock(&(philosopher->structure
					->forks[philosopher->left]))
			, pthread_mutex_unlock(&(philosopher
					->structure->forks[philosopher->right])), 1);
	philosopher_eats(philosopher);
	pthread_mutex_unlock(&(philosopher->structure
			->forks[philosopher->left]));
	pthread_mutex_unlock(&(philosopher->structure
			->forks[philosopher->right]));
	if (philosopher_dead(philosopher))
		return (1);
	philosopher_sleeps(philosopher);
	if (philosopher_dead(philosopher))
		return (1);
	printf("%ld Philosopher %d is thinking\n",
		get_time_now(philosopher->structure), philosopher->id);
	return (0);
}

void	*start_routine(void *philo_pointer)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo_pointer;
	while (1)
	{
		if (philosopher_takes_forks(philosopher) == 0)
		{
			if (when_forks_taken(philosopher) != 0)
				return (NULL);
		}
		if (philosopher_dead(philosopher))
			return (NULL);
	}
	return (NULL);
}

int	check_meals(t_struct *structure)
{
	int	j;

	j = 0;
	if (structure->n_must_eat == -1)
		return (0);
	while (j <= structure->number_of_philosophers)
	{
		pthread_mutex_lock(&(structure->philosophers[j].philomutex));
		if (structure->philosophers[j].meals >= structure->n_must_eat)
		{
			pthread_mutex_unlock(&(structure->philosophers[j].philomutex));
			j++;
		}
		else
			pthread_mutex_unlock(&(structure->philosophers[j].philomutex));
		if (j >= structure->number_of_philosophers)
		{
			stop_setter(structure);
			return (1);
		}
	}
	return (0);
}

void	monitor(t_struct *structure)
{
	long	time_now;
	int		i;

	while (1)
	{
		i = 0;
		while (i < structure->number_of_philosophers)
		{
			pthread_mutex_lock(&(structure->philosophers[i].philomutex));
			time_now = get_time_now(structure);
			if (time_now > (structure->philosophers[i]
					.last_meal_time + structure->time_to_die))
			{
				stop_setter(structure);
				printf("%ld Philosopher %d died\n",
					time_now, structure->philosophers[i].id);
				pthread_mutex_unlock(&(structure->philosophers[i].philomutex));
				return ;
			}
			pthread_mutex_unlock(&(structure->philosophers[i].philomutex));
			if (check_meals(structure) != 0)
				return ;
			i++;
		}
	}
}

int	philosophers(char **argv)
{
	t_struct	structure;
	int			result;
	int			i;

	i = 0;
	if (init_info(&structure, argv) == 1 || init_philosophers(&structure) == 1)
	{
		write(2, "Error - input is not valid\n", 27);
		return (1);
	}
	result = run_threads(&structure);
	monitor(&structure);
	while (i < structure.number_of_philosophers)
	{
		pthread_join(structure.philosophers[i].thread_id, NULL);
		i++;
	}
	free_and_destroy(&structure);
	return (result);
}
