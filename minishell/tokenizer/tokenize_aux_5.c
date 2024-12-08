/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:11:49 by albealva          #+#    #+#             */
/*   Updated: 2024/11/11 14:26:27 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r');
}

char	*get_env_var(t_general *info, const char *var_name)
{
	int		i;
	char	*equal_sign;
	size_t	name_length;

	i = 0;
	while (info->env[i] != NULL)
	{
		equal_sign = ft_strchr(info->env[i], '=');
		if (equal_sign != NULL)
		{
			name_length = equal_sign - info->env[i];
			if (ft_strncmp(info->env[i], var_name, name_length) == 0
				&& name_length == ft_strlen(var_name))
				return (equal_sign + 1);
		}
		i++;
	}
	return ("");
}

int	is_special_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\'' || c == '\"' || c == '<'
		|| c == '>' || c == '|' || c == '$');
}
