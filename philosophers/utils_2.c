/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:07:24 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/08 21:10:20 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philosopher_dead(t_philo *philosopher)
{
    long    time_now;

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

