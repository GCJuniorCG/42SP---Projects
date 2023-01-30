/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:13:10 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 13:13:12 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	msg_error(t_game *game, char *msg, int trigger)
{
	clean_game(game, trigger);
	ft_putstr(msg);
	exit (1);
}
