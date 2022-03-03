/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:45:46 by abaioumy          #+#    #+#             */
/*   Updated: 2022/03/03 14:19:16 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_convert_to_binary(str[i], pid);
		i++;
	}
	ft_printf("received full string\n");
	ft_convert_to_binary('\n', pid);
}

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_atoi(av[1]);
	if (ac != 3)
		return (0);
	ft_send_char(av[2], pid);
	return (0);
}
