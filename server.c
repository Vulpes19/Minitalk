/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:30:37 by abaioumy          #+#    #+#             */
/*   Updated: 2022/02/23 15:10:12 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler1(int signum)
{
	(void)signum;
	ft_printf("1");
}

void	sig_handler0(int signum)
{
	(void)signum;
	ft_printf("0");
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		return (0);
	}
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler0);
	while (1)
		pause();
	return (0);
}
