/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:52:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/08 23:00:52 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list arg, int *count)
{
	int		int_arg;
	char	c;

	int_arg = va_arg(arg, int);
	c = (char)int_arg;
	count++;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
