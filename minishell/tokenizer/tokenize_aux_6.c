/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:27:34 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 18:42:41 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_dollars(const char *section)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (section[i] != '\0')
	{
		if (section[i] == '$')
			count++;
		i++;
	}
	return (count);
}

void	print_start_pos(int *start_pos)
{
	int	i;

	i = 0;
	printf("Contenido de start_pos: ");
	while (start_pos[i])
	{
		printf("%d ", start_pos[i]);
		i++;
	}
	printf("\n");
}

int	reset_positions(int *start_pos, int size_malloc)
{
	int	k;

	k = 0;
	if (start_pos == NULL)
		return (-1);
	while (k < size_malloc)
	{
		start_pos[k] = -1;
		k++;
	}
	return (0);
}
