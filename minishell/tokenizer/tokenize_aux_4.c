/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:03:19 by albealva          #+#    #+#             */
/*   Updated: 2024/11/11 14:05:46 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extract_section(char **start, const char *delimiters, t_general *info)
{
	char	*end;
	char	*section;
	int		in_single_quotes;
	int		in_double_quotes;

	init_extract_section(&in_single_quotes, &in_double_quotes);
	if (**start == '|')
	{
		section = my_malloc(info, 2);
		if (!section)
			error_malloc();
		section[0] = '|';
		section[1] = '\0';
		(*start)++;
		return (section);
	}
	end = *start;
	while (*end && (!strchr(delimiters, *end) || in_single_quotes
			|| in_double_quotes))
	{
		update_quotes(*end, &in_single_quotes, &in_double_quotes);
		end++;
	}
	section = allocate_and_copy_section(start, end, info);
	return (section);
}

char	*append_string(char *dest, char *src)
{
	size_t	src_len;
	size_t	dest_len;

	if (dest == NULL || src == NULL)
		return (NULL);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	dest = my_realloc_char(dest, dest_len + src_len + 1);
	if (dest == NULL)
	{
		fprintf(stderr, "Error reallocating memory\n");
		return (NULL);
	}
	ft_strcat(dest, src);
	return (dest);
}

void	add_token_to_list(t_general *info, const char *str, int type)
{
	t_token	*new_token;
	t_token	*last;

	new_token = my_malloc(info, sizeof(t_token));
	if (!new_token)
		error_malloc();
	new_token->str = trolft_strdup(str, info);
	if (!new_token->str)
		error_malloc();
	new_token->type = type;
	new_token->prev = NULL;
	new_token->next = NULL;
	if (!info->tokens_list)
		info->tokens_list = new_token;
	else
	{
		last = info->tokens_list;
		while (last->next)
			last = last->next;
		last->next = new_token;
		new_token->prev = last;
	}
	info->number_of_tokens++;
}

char	*add_char_to_token2(t_general *info, char *token, char c)
{
	int		len;
	char	*new_token;

	if (token != NULL)
		len = ft_strlen(token);
	else
		len = 0;
	new_token = my_malloc(info, len + 2);
	if (!new_token)
		return (NULL);
	if (token)
		ft_strcpy(new_token, token);
	new_token[len] = c;
	new_token[len + 1] = '\0';
	return (new_token);
}

char	*add_char_to_token(t_general *info, char *token, char c)
{
	int		len;
	char	*new_token;

	if (token != NULL)
		len = ft_strlen(token);
	else
		len = 0;
	new_token = my_malloc(info, len + 2);
	if (!new_token)
		return (NULL);
	if (token)
		ft_strcpy(new_token, token);
	if (is_marked(c))
		c = unmark_char(c);
	new_token[len] = c;
	new_token[len + 1] = '\0';
	return (new_token);
}
