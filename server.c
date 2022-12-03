/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:47:34 by azakarya          #+#    #+#             */
/*   Updated: 2022/12/03 19:19:46 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 1;

	(void)context;
	(void)info;
	c <<= 1;
	if (sig == SIGUSR1)
		c = c | 1;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	++i;
}

int	main(void)
{
	t_sigaction	server;
	pid_t		id;

	id = getpid();
	write(1, "process id: ", ft_strlen("process id: "));
	write(1, ft_itoa(id), ft_strlen(ft_itoa(id)));
	write(1, "\n", 1);
	server.sa_sigaction = &handler;
	server.sa_flags = SA_SIGINFO;
	server.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
		pause();
	return (0);
}
