/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:40:50 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/13 21:47:20 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		check_pid(char *str);
void	str_to_b(int pid, char *message);
void	char_to_b(int pid, char byte);
void	handle_sig(int sig, siginfo_t *info, void *param);
void	serv_handle(int signal);
int		check_pid(char *str);

#endif