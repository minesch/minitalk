/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:47:46 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/29 04:30:58 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	handler(int sig)
{
	unsigned char	c;
	int				i;

	i = 0;
	c = 0;
	++i;
	c <<= 1;
	printf("%d\n", __LINE__);
	if (sig == SIGUSR1)
		c |= 1;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
	}
}

int	main(void)
{
	t_sigaction	server;
	pid_t		id;

	id = getpid();
	ft_printf("process ID %d\n", id);
	server.sa_handler = &handler;
	server.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
		pause();
	return (0);
}
