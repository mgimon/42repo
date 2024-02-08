/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:26:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/23 20:28:30 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_min(int fd)
{
	int			i;
	const char	*str;

	i = 0;
	str = "-2147483648";
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	divider;
	char	c;

	divider = 1;
	if (n == -2147483648)
		print_min(fd);
	else
	{
		if (n < 0)
		{
			write(fd, &"-", 1);
			n = -n;
		}
		while (n / divider >= 10)
			divider *= 10;
		while (divider > 0)
		{
			c = n / divider + '0';
			write(fd, &c, 1);
			n = n % divider;
			divider = divider / 10;
		}
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2585845, 1);
	return (0);
}
*/
