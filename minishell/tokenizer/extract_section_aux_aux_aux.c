/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_section_aux_aux_aux.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:19:58 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 18:20:17 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_reset_section_state(t_section_args *args, t_general *info)
{
	args->current_section = append_to_current_section(info,
			args->current_section, args->current_token);
	args->current_token = NULL;
	args->j = reset_positions(args->start_pos, args->size_malloc);
	args->j = 0;
	args->quote_state = NONE;
}
