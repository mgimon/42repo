/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:24:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/24 21:28:42 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_takes_forks(t_philo *philosopher)
{
	
}

int	philosopher_eats(t_philo *philosopher)
{

}

void	*start_routine(void *philo_pointer)
{
	t_philo *philosopher;
	philosopher = (t_philo *)philo_pointer;
/*	while (philosopher->structure->one_dead == 0)
	{
	break si muere (+ setear one_dead = 1) y si llega al numero de comidas	*/
	if (philosopher_takes_forks(philosopher) == 0)
		philosopher_eats(philosopher);
/*	}*/
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
