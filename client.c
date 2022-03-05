/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:45:46 by abaioumy          #+#    #+#             */
/*   Updated: 2022/03/05 16:31:34 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_printf("PID must be a number\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_send_char(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_convert_to_binary(str[i], pid);
		i++;
	}
	ft_printf("String is sent successfully\n");
	ft_convert_to_binary('\n', pid);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("wrong input!\n");
		ft_printf("./client [PID] [STRING TO SEND]\n");
		exit(0);
	}
	if (!ft_is_number(av[1]))
		exit(0);
	pid = ft_atoi(av[1]);
	if (pid < 0)
	{
		ft_printf("PID is wrong !\n");
		exit(0);
	}
	ft_send_char(av[2], pid);
	return (0);
}
