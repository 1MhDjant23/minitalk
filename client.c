/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:39:22 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/13 21:51:23 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(int pid, char byte)
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

int	check_arg(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf("\033[0;31m IV PID\033[m\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	str_to_bin(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		char_to_bin(pid, message[i]);
		usleep(42);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		if (check_arg(argv[1]) == -1)
			exit(1);
		pid = ft_atoi(argv[1]);
		str_to_bin(pid, argv[2]);
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
