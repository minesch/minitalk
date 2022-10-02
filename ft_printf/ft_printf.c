/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:17:17 by azakarya          #+#    #+#             */
/*   Updated: 2022/04/12 22:01:10 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.

#include "ft_printf.h"

static void	handle(const char *format, va_list *ap, int *i, int *count)
{
	if (format[*i] == '%')
		*count += ft_putchar('%');
	if (format[*i] == 'c')
		*count += ft_putchar(va_arg(*ap, int));
	if (format[*i] == 's')
		*count += ft_putstr(va_arg(*ap, char *));
	if (format[*i] == 'p')
		*count += ft_putptr(va_arg(*ap, void *));
	if (format[*i] == 'd' || format[*i] == 'i')
		*count += ft_putnbr(va_arg(*ap, int));
	if (format[*i] == 'u')
		*count += ft_putunbr(va_arg(*ap, unsigned int));
	if (format[*i] == 'x')
		*count += ft_putnbr_hex(va_arg(*ap, unsigned int), 'x');
	if (format[*i] == 'X')
		*count += ft_putnbr_hex(va_arg(*ap, unsigned int), 'X');
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			handle(format, &ap, &i, &count);
		}
		else
			count += ft_putchar(format[i]);
	}
	va_end(ap);
	return (count);
}
