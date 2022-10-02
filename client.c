/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:15:38 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/29 04:27:04 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + ((int)*str - '0');
		str++;
	}
	return (res);
}

void	send_sig(int sig, char *str)
{
	int		n;
	char	c;

	while (*str)
	{
		n = 8;
		c = *str++;
		while (n--)
		{
			printf("%d\n", __LINE__);
			if (c >> n & 1)
				kill(sig, SIGUSR1);
			else
				kill(sig, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int ac, char **av)
{
	t_sigaction	client;

	if (ac != 3)
	{
		write(2, "error\n", ft_strlen("error\n"));
		return (1);
	}
	send_sig(ft_atoi(av[1]), av[2]);
	return (0);
}
