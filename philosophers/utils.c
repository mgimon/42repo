/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:01:08 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/15 17:32:44 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_destroy(t_struct *structure)
{
	int	i;

	i = 0;
	if (structure == NULL || structure->philosophers == NULL)
		return ;
	if (structure->number_of_philosophers == 1)
	{
		pthread_mutex_destroy(&(structure->philosophers[0].philomutex));
		free(structure->philosophers);
		pthread_mutex_destroy(&(structure->mutex));
		pthread_mutex_destroy(structure->forks);
		free(structure->forks);
		return ;
	}
	while (i < structure->number_of_philosophers)
	{
		pthread_mutex_destroy(&(structure->philosophers[i].philomutex));
		pthread_mutex_destroy(&(structure->forks[i]));
		i++;
	}
	free(structure->forks);
	free(structure->philosophers);
	pthread_mutex_destroy(&(structure->mutex));
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

void	waiter(t_philo *philosopher, long time)
{
	long	start;

	start = get_time_now(philosopher->structure);
	while ((get_time_now(philosopher->structure) - start)
		< time && philosopher_dead(philosopher) == 0)
		usleep(50);
}

long	get_time_now(t_struct *structure)
{
	struct timeval	timevalue;
	long			result;	

	gettimeofday(&timevalue, NULL);
	result = timevalue.tv_sec * 1000 + timevalue.tv_usec / 1000;
	result = result - structure->start_time;
	return (result);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
