/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:45:46 by abaioumy          #+#    #+#             */
/*   Updated: 2022/02/28 12:01:33 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_atoi(av[1]);
	if (ac != 3)
	{
		return (0);
	}
	ft_convert_to_binary(av[2], pid);
	return (0);
}
