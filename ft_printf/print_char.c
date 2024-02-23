/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:52:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/10 22:40:49 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list arg, int *count)
{
	int		int_arg;
	char	c;

	int_arg = va_arg(arg, int);
	c = (char)int_arg;
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (*count);
}
