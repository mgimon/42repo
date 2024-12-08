/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:26:33 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/02 21:05:59 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
static char	*expand_var(const char *input, t_general *info)
{
	int		i;
	char	*result;
	int		len;
	char	temp[1024] = {0};
	char	var_name[256] = {0};
	int		temp_index;
	int		var_index;
	char	*exit_status_str;
	char	*value;

	result = NULL;
	len = strlen(input);
	temp_index = 0;
	var_index = 0;
	i = 0;
	while (i < len)
	{
		if (input[i] == '$' && input[i + 1] == '?')
		{
			i += 1;
			expandvar_hlp_one(info, &exit_status_str, &temp, &temp_index);
			continue ;
		}
		if (input[i] == '$')
		{
			i++;
			var_index = 0;
			while (i < len && !is_special_separator(input[i])
				&& (isalnum(input[i]) || input[i] == '_'))
				var_name[var_index++] = input[i++];
			i--;
			var_name[var_index] = '\0';
			value = get_env_var(info, var_name);
			if (value)
			{
				strcpy(temp + temp_index, value);
				temp_index += strlen(value);
			}
		}
		else
			temp[temp_index++] = input[i];
		i++;
	}
	result = strdup(temp);
	return (result);
}*/

void	write_in_heredocs_helper(t_heredoc *tmp_hdoc, char *buffer,
		t_general *info)
{
	int		len;
	char	*expanded;

	while (1)
	{
		write(1, "> ", 2);
		len = read(0, buffer, 1023);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		if (ft_strcmp(buffer, tmp_hdoc->delimiter) == 0)
			break ;
		expanded = extract_current_section(buffer, info);
		if (expanded)
		{
			if (write_heredocs_norminetter(&len, &expanded, &tmp_hdoc) == 1)
				return ;
		}
	}
}

void	iterate_str(const char **str, int *sign, long *result)
{
	*sign = 1;
	*result = 0;
	while (**str == ' ' || **str == '\t')
		(*str)++;
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

int	ft_atol_overflow(const char *str, long *result)
{
	int	sign;
	int	digit;

	iterate_str(&str, &sign, result);
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (sign == 1 && (*result > (LONG_MAX - digit) / 10))
		{
			*result = LONG_MAX;
			return (-1);
		}
		else if (sign == -1 && (*result > (LONG_MIN + digit) / -10))
		{
			*result = LONG_MIN;
			return (-1);
		}
		*result = *result * 10 + digit;
		str++;
	}
	if (*str != '\0')
		return (-2);
	*result *= sign;
	return (0);
}

void	check_argc_exit(t_section *current)
{
	if (current->cmdv[2])
	{
		put_str_fd(2, "Exit: too many arguments\n");
		exit(1);
	}
}
