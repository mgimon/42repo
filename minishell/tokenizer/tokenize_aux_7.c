/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:06 by albealva          #+#    #+#             */
/*   Updated: 2024/11/15 15:04:32 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand_dollar_question(t_general *info)
{
	char	*result;

	result = (char *)my_malloc(info, 12);
	if (result == NULL)
		return (NULL);
	result = trolft_itoa(info->exit_status, info);
	return (result);
}

char	mark_char(char c)
{
	return (c | 0x80);
}

unsigned char	unmark_char(unsigned char c)
{
	if (c == 0xA4 || c == 0xA2 || c == 0xA7)
		return (c & 0x7F);
	return (c);
}

int	is_marked(char c)
{
	return ((c & 0x80) != 0);
}
