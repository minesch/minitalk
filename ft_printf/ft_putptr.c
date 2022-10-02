/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:11:10 by azakarya          #+#    #+#             */
/*   Updated: 2022/04/12 21:22:51 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	puthex(void *ptr)
{
	int						i;
	unsigned long long int	b;

	b = (unsigned long long int)ptr;
	i = 0;
	if (b >= 16)
	{
		i += puthex((void *)(b / 16));
		i += puthex((void *)(b % 16));
	}
	else
	{
		if (b < 10)
			i += ft_putchar(b + '0');
		if (b > 9)
			i += ft_putchar(b - 10 + 'a');
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		i += ft_putstr("0x0");
		return (i);
	}
	i += ft_putstr("0x");
	i += puthex(ptr);
	return (i);
}
