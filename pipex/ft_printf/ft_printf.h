/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:54:56 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/22 17:17:38 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(char const *fmt, ...);

int		print_char(va_list arg, int *count);

int		print_string(va_list arg, int *count);

int		print_pointer(va_list arg, int *count);

int		print_integer(va_list arg, int *count);

int		print_unsigned(va_list arg, int *count);

int		print_hex(unsigned long num, int *count, char c);

int		print_percent(int *count);
#endif
