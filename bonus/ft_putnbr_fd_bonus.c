/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:26:40 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/08 12:05:11 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putnbr_fd(long n, int fd)
{
	unsigned long	x;
	char			c;

	x = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		x = -n;
	}
	if (x < 10)
	{
		c = x + 48;
		write(fd, &c, 1);
	}
	else if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
}
