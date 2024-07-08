/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:24:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/08 19:44:58 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *philo_pointer)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo_pointer;
	while (1)
	{
		if (philosopher_takes_forks(philosopher) == 0)
		{
			if (philosopher_dead(philosopher))
				return (pthread_mutex_unlock(&(philosopher->structure
							->forks[philosopher->left]))
					, pthread_mutex_unlock(&(philosopher
							->structure->forks[philosopher->right])), NULL);
			philosopher_eats(philosopher);
			pthread_mutex_unlock(&(philosopher->structure
					->forks[philosopher->left]));
			pthread_mutex_unlock(&(philosopher->structure
					->forks[philosopher->right]));
			if (philosopher_dead(philosopher))
				return (NULL);
			philosopher_sleeps(philosopher);
			if (philosopher_dead(philosopher))
				return (NULL);
			printf("%ld Philosopher %d is thinking\n",
				get_time_now(philosopher->structure), philosopher->id);
		}
		if (philosopher_dead(philosopher))
			return (NULL);
	}
	return (NULL);
}

void	stop_setter(t_struct *structure)
{
	pthread_mutex_lock(&structure->mutex);
	structure->one_dead_or_done = 1;
	pthread_mutex_unlock(&structure->mutex);
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
			time_now = get_time_now(structure);
			if (time_now > (structure->philosophers[i].last_meal_time
					+ structure->time_to_die))
			{
				stop_setter(structure);
				printf("%ld Philosopher %d died\n", time_now,
					structure->philosophers[i].id);
				return ;
			}
			else if (structure->n_must_eat != -1 && structure
				->philosophers[i].meals >= structure->n_must_eat)
			{
				stop_setter(structure);
				return ;
			}
			i++;
		}
	}
}

int	run_threads(t_struct *structure)
{
	int	i;

	i = 0;
	while (i < structure->number_of_philosophers)
	{
		pthread_create(&structure->philosophers[i].thread_id, NULL,
			&start_routine, (void *)&structure->philosophers[i]);
		i++;
	}
	return (0);
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
