/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:56:29 by azakarya          #+#    #+#             */
/*   Updated: 2022/04/12 22:11:09 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putnbr_hex(unsigned int nb, char x)
{
	int		i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_putnbr_hex(nb / 16, x);
		i += ft_putnbr_hex(nb % 16, x);
	}
	else
	{
		if (nb < 10)
			i += ft_putchar(nb + '0');
		if (nb > 9 && x == 'X')
			i += ft_putchar(nb - 10 + 'A');
		if (nb > 9 && x == 'x')
			i += ft_putchar(nb - 10 + 'a');
	}
	return (i);
}
