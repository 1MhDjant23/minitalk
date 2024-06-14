/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:28:44 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/13 21:30:59 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern int	g_pid_serv;

int	check_pid(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf("\033[0;31m IV PID \033[m\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	serv_handle(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("The Server With\033[0;36m PID \033[m");
		ft_printf("[\033[0;32m%d\033[m]", g_pid_serv);
		ft_printf(" has successfully received the message.\n");
	}
}
