/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:48:00 by azakarya          #+#    #+#             */
/*   Updated: 2022/12/03 19:26:11 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

int	g_lenght;

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
	int		i;

	i = 0;
	while (str[i])
	{
		n = 8;
		while (n--)
		{
			if (str[i] >> n & 1)
				kill(sig, SIGUSR1);
			else
				kill(sig, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

void	handler(int sig)
{
	static int	i;

	(void)sig;
	if (++i == g_lenght)
	{
		write(1, "Message_received!\n", 18);
		i = 0;
	}
}

int	main(int ac, char **av)
{
	t_sigaction	client;

	client.sa_handler = handler;
	client.sa_flags = SA_SIGINFO;
	client.sa_flags = SA_RESTART;
	if (ac == 3)
	{
		g_lenght = ft_strlen(av[2]);
		sigaction(SIGUSR1, &client, NULL);
		send_sig(ft_atoi(av[1]), av[2]);
	}
	else
	{
		write(2, "error\n", ft_strlen("error\n"));
		return (1);
	}
	return (0);
}
