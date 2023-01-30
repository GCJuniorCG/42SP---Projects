/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:22:55 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:22:56 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int	is_negative;
	int	result;

	result = 0;
	is_negative = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		is_negative = 1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = 10 * result - (int)(*nptr - '0');
		nptr++;
	}
	if (is_negative)
		return (result);
	return (-result);
}
