/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:14:16 by abaioumy          #+#    #+#             */
/*   Updated: 2022/03/03 14:22:39 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_convert_to_binary(char c, int pid)
{
	int		shift;

	shift = 0;
	while (shift < 8)
	{
		if (c & (0x80 >> shift))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		shift++;
		usleep(100);
	}
}

int	ft_atoi(char *str)
{
	int					i;
	unsigned long long	result;
	int					sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	// if (result >= (unsigned long long)9223372036854775807 + 1 && sign == -1)
	// 	return (0);
	// if (result > 9223372036854775807 && sign == 1)
	// 	return (-1);
	return (result * sign);
}
