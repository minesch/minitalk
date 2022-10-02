/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:18:12 by azakarya          #+#    #+#             */
/*   Updated: 2022/04/13 02:49:28 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include <stdio.h>

int	ft_putstr(const char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
