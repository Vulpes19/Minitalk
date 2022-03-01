/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:30:37 by abaioumy          #+#    #+#             */
/*   Updated: 2022/02/28 16:17:01 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;
	char		*str;
	int			pid;
	int			i;

	i = 0;
	pid = getpid();
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	bits++;
	i++;
	if (c == '\0')
	{
		ft_printf("\nreceived full string\n");
		c = 0xFF;
	}
	if (bits == 8)
	{
		str[i] = c;
		ft_printf("%c\n", c);
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	printf("PID: %d\n", getpid());
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
}
// void	sig_handler(int signum)
// {
// 	static char	c;
// 	static int	bits;

// 	c = 0xFF;
// 	bits = 0;
// 	if (signum == SIGUSR1)
// 	{
// 		ft_printf("0");
// 		c ^= 0x80 >> bits;
// 	}
// 	else if (signum == SIGUSR2)
// 	{
// 		ft_printf("1");
// 		c |= 0x80 >> bits;
// 	}
// 	bits++;
// 	// ft_printf("bits: %d\n", bits);
// 	if (bits == 8)
// 	{
// 		ft_printf("-> %c\n", c);
// 		bits = 0;
// 		c = 0xFF;
// 	}
// }

// int	main(void)
// {
// 	ft_printf("PID: %d\n", getpid());
// 	signal(SIGUSR1, sig_handler);
// 	signal(SIGUSR2, sig_handler);
// 	while (1)
// 		pause();
// }
