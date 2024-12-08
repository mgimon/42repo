/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:12:27 by albealva          #+#    #+#             */
/*   Updated: 2024/11/15 14:18:22 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_advance_until_delim(char *start, const char *delim)
{
	while (*start && ft_strchr(delim, *start))
		start++;
	return (start);
}

int	ft_advance_until_delim_index(char *start, const char *delim, int i)
{
	while (start[i] && !ft_strchr(delim, start[i]))
		i++;
	return (i);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last;
	char		*start;
	int			i;

	if (str != NULL)
		last = str;
	if (last == NULL)
		return (NULL);
	start = last;
	start = ft_advance_until_delim(start, delim);
	if (*start == '\0')
	{
		last = NULL;
		return (NULL);
	}
	i = 0;
	i = ft_advance_until_delim_index(start, delim, i);
	if (start[i] != '\0')
	{
		start[i] = '\0';
		last = &start[i + 1];
	}
	else
		last = NULL;
	return (start);
}

int	ft_is_builtin(const char *command)
{
	if (ft_strcmp(command, "echo") == 0 || ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "pwd") == 0 || ft_strcmp(command, "export") == 0
		|| ft_strcmp(command, "unset") == 0 || ft_strcmp(command, "env") == 0
		|| ft_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

int	is_valid_command(t_general *info, const char *command, char **env)
{
	char	*path;
	char	full_path[512];
	char	*path_copy;
	char	*dir;

	(void)env;
	if (ft_is_builtin(command))
		return (1);
	path = getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "Error: PATH variable not found.\n");
		return (0);
	}
	path_copy = trolft_strdup(path, info);
	dir = ft_strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
			return (1);
		dir = ft_strtok(NULL, ":");
	}
	return (0);
}
