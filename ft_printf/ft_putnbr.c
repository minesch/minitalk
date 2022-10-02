/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:50:59 by azakarya          #+#    #+#             */
/*   Updated: 2022/04/10 00:57:30 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putnbr(int nb)
{
	long	x;
	int		i;

	i = 0;
	x = nb;
	if (x < 0)
	{
		x = -x;
		i += ft_putchar('-');
	}
	if (x >= 10)
	{
		i += ft_putnbr(x / 10);
		i += ft_putnbr(x % 10);
	}
	else
		i += ft_putchar(x + '0');
	return (i);
}
