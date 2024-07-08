/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:18:15 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/08 20:29:12 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_dead(t_philo *philosopher)
{
	long	time_now;

	time_now = get_time_now(philosopher->structure);
	pthread_mutex_lock(&philosopher->structure->mutex);
	if (philosopher->structure->one_dead_or_done == 1)
	{
		pthread_mutex_unlock(&philosopher->structure->mutex);
		return (1);
	}
	if (time_now > (philosopher->last_meal_time
			+ philosopher->structure->time_to_die))
	{
		philosopher->structure->one_dead_or_done = 1;
		pthread_mutex_unlock(&(philosopher->structure->mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philosopher->structure->mutex));
	return (0);
}

int	philosopher_takes_forks(t_philo *philosopher)
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
	if (philosopher->structure->number_of_philosophers == 1)
		return (waiter(philosopher, philosopher->structure->time_to_die + 100),
			pthread_mutex_unlock(&(philosopher
					->structure->forks[philosopher->right])), 1);
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
	if (philosopher_dead(philosopher))
	{
		pthread_mutex_unlock(&(philosopher
				->structure->forks[philosopher->left]));
		pthread_mutex_unlock(&(philosopher
				->structure->forks[philosopher->right]));
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
	philosopher->last_meal_time = get_time_now(philosopher->structure);
	waiter(philosopher, philosopher->structure->time_to_eat);
	philosopher->meals++;
	return (0);
}

int	philosopher_sleeps(t_philo *philosopher)
{
	printf("%ld Philosopher %d is sleeping\n",
		get_time_now(philosopher->structure), philosopher->id);
	waiter(philosopher, philosopher->structure->time_to_sleep);
	return (0);
}
