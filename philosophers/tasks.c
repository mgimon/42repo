/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:18:15 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/15 18:05:10 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_first(t_philo *philosopher)
{
	if (philosopher->id % 2 == 0)
		pthread_mutex_lock(&(philosopher
				->structure->forks[philosopher->right]));
	else
		pthread_mutex_lock(&(philosopher
				->structure->forks[philosopher->left]));
	if (philosopher_dead(philosopher))
	{
		if (philosopher->id % 2 == 0)
			pthread_mutex_unlock(&(philosopher
					->structure->forks[philosopher->right]));
		else
			pthread_mutex_unlock(&(philosopher
					->structure->forks[philosopher->left]));
		return (1);
	}
	else
		printf("%ld Philosopher %d has taken a fork\n",
			get_time_now(philosopher->structure), philosopher->id);
	return (0);
}

int	take_second(t_philo *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		if (pthread_mutex_lock(&(philosopher
					->structure->forks[philosopher->left])) != 0)
			return (pthread_mutex_unlock(&(philosopher
						->structure->forks[philosopher->right])), 1);
	}
	else
	{
		if (pthread_mutex_lock(&(philosopher
					->structure->forks[philosopher->right])) != 0)
			return (pthread_mutex_unlock(&(philosopher
						->structure->forks[philosopher->left])), 1);
	}
	return (0);
}

int	philosopher_takes_forks(t_philo *philosopher)
{
	if (take_first(philosopher) != 0)
		return (1);
	if (philosopher->structure->number_of_philosophers == 1)
		return (waiter(philosopher, philosopher->structure->time_to_die + 100),
			pthread_mutex_unlock(&(philosopher
					->structure->forks[philosopher->left])), 1);
	if (take_second(philosopher) != 0)
		return (1);
	if (philosopher_dead(philosopher))
	{
		pthread_mutex_unlock(&(philosopher
				->structure->forks[philosopher->left]));
		pthread_mutex_unlock(&(philosopher
				->structure->forks[philosopher->right]));
		return (1);
	}
	else
		printf("%ld Philosopher %d has taken a fork\n",
			get_time_now(philosopher->structure), philosopher->id);
	return (0);
}

int	philosopher_eats(t_philo *philosopher)
{
	printf("%ld Philosopher %d is eating\n",
		get_time_now(philosopher->structure), philosopher->id);
	pthread_mutex_lock(&(philosopher->philomutex));
	philosopher->last_meal_time = get_time_now(philosopher->structure);
	pthread_mutex_unlock(&(philosopher->philomutex));
	waiter(philosopher, philosopher->structure->time_to_eat);
	pthread_mutex_lock(&(philosopher->philomutex));
	philosopher->meals++;
	pthread_mutex_unlock(&(philosopher->philomutex));
	return (0);
}

int	philosopher_sleeps(t_philo *philosopher)
{
	printf("%ld Philosopher %d is sleeping\n",
		get_time_now(philosopher->structure), philosopher->id);
	waiter(philosopher, philosopher->structure->time_to_sleep);
	return (0);
}
