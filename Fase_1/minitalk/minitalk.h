/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:21:52 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 18:09:31 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 1024

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <libft.h>

void	send_error(int pid, int sig_num);

#endif
