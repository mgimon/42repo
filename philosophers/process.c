/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:24:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/27 18:32:03 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_dead(t_philo *philosopher)
{
	long	time_now;

	time_now = get_time_now();
	if (philosopher->structure->one_dead == 1)
		return (1);
	if (time_now > (philosopher->last_meal_time + philosopher->structure->time_to_die))
	{
		philosopher->structure->one_dead = 1;
		printf("%ld Philosopher %d died\n", time_now, philosopher->id);
		return (1);
	}
	return (0);
}

void    waiter(t_philo *philosopher, long time)
{
	long	start;

	start = get_time_now();
	while ((get_time_now() - start) < time && philosopher_dead(philosopher) == 0)
		usleep(50);
}

int	philosopher_takes_forks(t_philo *philosopher)
{
	if (philosopher->id % 2 == 0)
		pthread_mutex_lock(&(philosopher->structure->forks[philosopher->right]));
	else
		pthread_mutex_lock(&(philosopher->structure->forks[philosopher->left]));
	if (!philosopher_dead(philosopher))
		printf("%ld Philosopher %d has taken a fork\n", get_time_now(), philosopher->id);
	if (philosopher->structure->number_of_philosophers == 1)
                return (waiter(philosopher, philosopher->structure->time_to_die + 100), pthread_mutex_unlock(&(philosopher->structure->forks[philosopher->right])), 1);
	if (philosopher->id % 2 == 0)
	{
		if (pthread_mutex_lock(&(philosopher->structure->forks[philosopher->left])) != 0)
			return (pthread_mutex_unlock(&(philosopher->structure->forks[philosopher->right])), 1);
		if (!philosopher_dead(philosopher))
			printf("%ld Philosopher %d has taken a fork\n", get_time_now(), philosopher->id);
	}
	else
	{
		if (pthread_mutex_lock(&(philosopher->structure->forks[philosopher->right])) != 0)
			return (pthread_mutex_unlock(&(philosopher->structure->forks[philosopher->left])), 1);
		if (!philosopher_dead(philosopher))
			printf("%ld Philosopher %d has taken a fork\n", get_time_now(), philosopher->id);
	}
	return (0);
}

int	philosopher_eats(t_philo *philosopher)
{
	printf("%ld Philosopher %d is eating\n", get_time_now(), philosopher->id);
	waiter(philosopher, philosopher->structure->time_to_eat);
	philosopher->last_meal_time = get_time_now();
	return (0);
}

int	philosopher_sleeps(t_philo *philosopher)
{
	printf("%ld Philosopher %d is sleeping\n", get_time_now(), philosopher->id);
	waiter(philosopher, philosopher->structure->time_to_sleep);
	return (0);
}

void	*start_routine(void *philo_pointer)
{
	t_philo *philosopher;
	philosopher = (t_philo *)philo_pointer;
	while (1)
	{
	// break si llega al numero de comidas
		if (philosopher_takes_forks(philosopher) == 0)
		{
			if (philosopher_dead(philosopher))
				return (pthread_mutex_unlock(&(philosopher->structure->forks[philosopher->left])), pthread_mutex_unlock(&(philosopher->structure->forks[philosopher->right])), NULL);
			philosopher_eats(philosopher);
			pthread_mutex_unlock(&(philosopher->structure->forks[philosopher->left]));
			pthread_mutex_unlock(&(philosopher->structure->forks[philosopher->right]));
			if (philosopher_dead(philosopher))
				return (NULL);
			philosopher_sleeps(philosopher);
			if (philosopher_dead(philosopher))
				return (NULL);
			printf("%ld Philosopher %d is thinking\n", get_time_now(), philosopher->id);
		}
		if (philosopher_dead(philosopher))
			return (NULL);
	}
	return (NULL);
}

int	run_threads(t_struct *structure)
{
	int i;

	i = 0;
	while (i < structure->number_of_philosophers)
	{
		pthread_create(&structure->philosophers[i].thread_id, NULL, &start_routine, (void *)&structure->philosophers[i]);
		i++;
	}
	i = 0;
	while (i < structure->number_of_philosophers)
	{
		pthread_join(structure->philosophers[i].thread_id, NULL);
		i++;
	}
	return (0);
}

int	philosophers(char **argv)
{
	t_struct	structure;
	int			result;

	if (init_info(&structure, argv) == 1 || init_philosophers(&structure) == 1)
	{
		write(2, "Error - input is not valid\n", 27);
		return (1);
	}
	result = run_threads(&structure);
	if (result != 0)
	{
		put_error(result);
		return (1);
	}
	return (0);
}
