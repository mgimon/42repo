/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:52:27 by albealva          #+#    #+#             */
/*   Updated: 2024/11/11 14:01:57 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_malloc(void)
{
	perror("Malloc failed");
	exit(EXIT_FAILURE);
}

void	error_strdup(void)
{
	perror("Strdup failed");
	exit(EXIT_FAILURE);
}

void	update_quotes(char current_char,
		int *in_single_quotes, int *in_double_quotes)
{
	if (current_char == '\'')
		*in_single_quotes = !(*in_single_quotes);
	else if (current_char == '\"')
		*in_double_quotes = !(*in_double_quotes);
}

void	init_extract_section(int *in_single_quotes, int *in_double_quotes)
{
	*in_single_quotes = 0;
	*in_double_quotes = 0;
}

char	*allocate_and_copy_section(char **start,
		char *end, t_general *info)
{
	size_t	section_length;
	char	*section;

	section_length = end - *start;
	section = my_malloc(info, section_length + 1);
	if (!section)
		error_malloc();
	ft_strncpy(section, *start, section_length);
	section[section_length] = '\0';
	*start = end;
	return (section);
}
