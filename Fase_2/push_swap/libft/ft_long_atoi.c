/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:58:06 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:58:09 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_long_atoi(const char *nptr)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	res = res * sign;
	return (res);
}
