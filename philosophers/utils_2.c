/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:07:24 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/08 21:40:35 by mgimon-c         ###   ########.fr       */
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

void	stop_setter(t_struct *structure)
{
	pthread_mutex_lock(&structure->mutex);
	structure->one_dead_or_done = 1;
	pthread_mutex_unlock(&structure->mutex);
}
