/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:30:37 by abaioumy          #+#    #+#             */
/*   Updated: 2022/03/05 15:51:31 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;
	int			pid;

	pid = getpid();
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0xFF;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("wrong input!\n");
		exit(0);
	}
	ft_printf("PID: %d\n", getpid());
	if (signal(SIGUSR1, handler_sigusr) == SIG_ERR)
	{
		ft_printf("signal error!\n");
		exit(0);
	}
	if (signal(SIGUSR2, handler_sigusr) == SIG_ERR)
	{
		ft_printf("signal error!\n");
		exit(0);
	}
	while (1)
		pause();
}
