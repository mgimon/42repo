/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:01:08 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/24 20:50:10 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long		get_time_now(void)
{
	struct	timeval		timevalue;
	long				result;
	

	gettimeofday(&timevalue, NULL);
	result = timevalue.tv_sec * 1000 + timevalue.tv_usec / 1000;
	return (result);
}

void	put_error(int error)
{
	if (error == 1)
		write(2, "Error - Malloc error\n", 21);
}

long ft_atol(const char *str)
{
	long result;
	int sign;

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
