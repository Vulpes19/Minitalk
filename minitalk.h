/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:30:51 by abaioumy          #+#    #+#             */
/*   Updated: 2022/03/12 15:58:12 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h> 

int		ft_atoi(char *str);
int		ft_isdigit(int c);
void	ft_convert_to_binary(unsigned char c, int pid);
int		ft_is_number(char *str);
int		ft_strlen(char *s);

#endif