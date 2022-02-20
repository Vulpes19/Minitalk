/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:14:16 by abaioumy          #+#    #+#             */
/*   Updated: 2022/02/20 21:34:01 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_convert_to_binary(int nbr)
{
	int	*binary;
	int	*result;
	int	i;
	int	j;

	i = 0;
	j = 0;
	binary = NULL;
	result = NULL;
	while (nbr / 2)
	{
		binary[i] = nbr % 2;
		nbr /= 2;
		i++;
	}
	while (i > 0)
	{
		result[j] = binary[i];
		i--;
		j++;
	}
	exit(0);
	j = *result;
	return (j);
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
	if (result >= (unsigned long long)9223372036854775807 + 1 && sign == -1)
		return (0);
	if (result > 9223372036854775807 && sign == 1)
		return (-1);
	return (result * sign);
}
