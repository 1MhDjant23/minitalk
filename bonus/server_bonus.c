/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:42:24 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/13 21:36:50 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_sig(int sig, siginfo_t *info, void *param)
{
	static pid_t	pid;
	static char		byte;
	static int		index;

	(void)param;
	if (info->si_uid != 101536)
		return ;
	if (pid != info->si_pid)
	{
		index = 0;
		byte = 0;
	}
	pid = info->si_pid;
	byte = byte | (sig == SIGUSR1);
	index++;
	if (index == 8)
	{
		ft_printf("%c", byte);
		if (byte == '\0')
			kill(info->si_pid, SIGUSR1);
		byte = 0;
		index = 0;
	}
	else
		byte = byte << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("<<<<<<<<<< PID %d >>>>>>>>\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sig;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(write(2, "Error\n", 6));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(write(2, "Error\n", 6));
	while (1)
		pause();
	return (0);
}
