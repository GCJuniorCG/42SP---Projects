/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:20:56 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:20:58 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	send_error(int pid, int sig_num)
{
	if (sig_num == SIGUSR1)
		ft_printf("Error: failed to send signal SIGUSR1 to PID %i\n", pid);
	else if (sig_num == SIGUSR2)
		ft_printf("Error: failed to send signal SIGUSR2 to PID %i\n", pid);
	else
		ft_printf(
			"Error: unknown signal error sending signal to PID %i\n", pid);
	exit(1);
}
