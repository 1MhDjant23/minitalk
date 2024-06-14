/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:45:55 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/13 21:40:56 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_pid_serv;

void	char_to_b(int pid, char byte)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (byte >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	str_to_b(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		char_to_b(pid, message[i]);
		usleep(42);
		i++;
	}
	if (message[i] == '\0')
		char_to_b(pid, message[i]);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		if (check_pid(argv[1]) == -1)
			exit(1);
		pid = ft_atoi(argv[1]);
		g_pid_serv = pid;
		signal(SIGUSR1, serv_handle);
		str_to_b(pid, argv[2]);
	}
	else
	{
		if (argc == 2)
			ft_printf("Enter MESSAGE!\n");
		if (argc == 1)
			ft_printf("Enter PID and MESSAGE!\n");
		exit(1); 
	}
	return (0);
}
