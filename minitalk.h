/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:04:41 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/13 21:44:07 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		check_arg(char *str);
void	str_to_bin(int pid, char *message);
void	char_to_bin(int pid, char byte);

#endif