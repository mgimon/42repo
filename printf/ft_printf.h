/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:54:56 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/08 22:55:56 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int		ft_printf(char const *fmt, ...);

int		print_char(va_list arg, int *count);

void	print_string(char const *fmt, int *count);

void	print_void(char const *fmt, int *count);

void	print_double(char const *fmt, int *count);

void	print_integer(char const *fmt, int *count);

void	print_unsigned(char const *fmt, int *count);

void	print_hexmin(char const *fmt, int *count);

void	print_hexmax(char const *fmt, int *count);

void	print_percent(char const *fmt, int *count);
