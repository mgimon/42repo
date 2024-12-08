/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:10:59 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 18:41:05 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_section(char *section, t_general *info)
{
	if (section)
	{
		extract_tokens(section, info);
		section = NULL;
	}
}

t_token	*tokenize_input(t_general *info, char *input)
{
	t_quote_state	state;
	char			*section;
	char			*start;
	const char		*section_delimiters = "|\n\r";

	open_quote(input, &state);
	start = input;
	info->tokens_list = NULL;
	while (*start)
	{
		section = extract_section(&start, section_delimiters, info);
		if (section)
		{
			process_section(section, info);
		}
	}
	return (info->tokens_list);
}

char	*my_sprintf_concat(const char *str1, const char *str2, t_general *info)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = 0;
	len2 = 0;
	while (str1[len1] != '\0')
		len1++;
	while (str2[len2] != '\0')
		len2++;
	result = (char *)my_malloc(info, len1 + len2 + 2);
	if (!result)
		error_malloc();
	ft_strcpy(result, str1);
	ft_strcat(result, " ");
	ft_strcat(result, str2);
	return (result);
}

char	*append_to_current_section(t_general *info, char *current_section,
		const char *token)
{
	char	*temp;

	if (current_section == NULL)
		current_section = trolft_strdup(token, info);
	else
	{
		temp = my_malloc(info, ft_strlen(current_section) + ft_strlen(token)
				+ 2);
		if (temp == NULL)
			error_malloc();
		temp = my_sprintf_concat(current_section, token, info);
		current_section = temp;
	}
	return (current_section);
}

void	trim_trailing_whitespace(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'))
	{
		len--;
	}
	while (str[len] != '\0')
	{
		str[len] = '\0';
		len++;
	}
}
