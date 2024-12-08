/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_19.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:07:16 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/09 21:26:00 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**allocate_path_parts(void)
{
	char	**path_parts;

	path_parts = malloc(100 * sizeof(char *));
	if (!path_parts)
		return (NULL);
	return (path_parts);
}

char	*allocate_result(const char *path)
{
	char	*result;

	result = malloc(strlen(path) + 1);
	if (!result)
		return (NULL);
	return (result);
}

int	handle_double_dot(char **path_parts, int count)
{
	if (count > 0)
	{
		count--;
		free(path_parts[count]);
	}
	return (count);
}

int	copy_path_part(const char *start, int length, char **path_parts, int count)
{
	path_parts[count] = malloc(length + 1);
	if (!path_parts[count])
		return (-1);
	memcpy(path_parts[count], start, length);
	path_parts[count][length] = '\0';
	return (count + 1);
}

void	free_allocated_parts(char **path_parts, int count, char *result)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(path_parts[i]);
		i++;
	}
	free(path_parts);
	free(result);
}
