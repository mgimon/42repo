/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:01 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/17 18:59:11 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	process;

	if (argc != 5 && argc != 6)
	{
		write(2, "Error - please execute with the expected arguments:\n\n", 53);
		write(2, "./philo\n\t", 9);
		write(2, "[number_of_philosophers]\n\t[time_to_die]\n\t", 41);
		write(2, "[time_to_eat]\n\t[time_to_sleep]\n\t", 32);
		write(2, "(opt)[number_of_times_each_philosopher_must_eat]\n\n", 50);
		return (1);
	}
	process = philosophers(argv);
	return (process);
}
