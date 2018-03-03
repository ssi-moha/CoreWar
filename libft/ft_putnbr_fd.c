/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:47:18 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:47:19 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr_positive(unsigned int nb, int fd)
{
	char	c;

	if (nb == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (nb >= 10)
			ft_putnbr_positive(nb / 10, fd);
		c = (nb % 10) + '0';
		ft_putchar_fd(c, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		nb = (n < 0) ? n * -1 : n;
		ft_putnbr_positive(nb, fd);
	}
}
