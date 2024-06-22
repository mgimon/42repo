/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:24:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/22 19:02:45 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *philo_pointer)
{
	t_philo *philosopher;

	philosopher = (t_philo *)philo_pointer;
	while (philosopher->dead == 0)
	{
		
	}
	return (0);
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
