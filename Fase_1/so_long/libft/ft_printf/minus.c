/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:36:50 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:36:53 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	__minus(const char **fmt, va_list ap)
{
	char	*buff;
	int		bw;
	int		n;

	++(*fmt);
	bw = 0;
	if (ft_isdigit(**fmt))
	{
		n = ft_atoi(*fmt);
		buff = ft_calloc(n + 1, sizeof(char));
		if (!buff)
			return (0);
		ft_memset(buff, ' ', n);
		while (!ft_strchr("cspdiuxX%", **fmt))
			++(*fmt);
		if (ft_strchr("cspdiuxX", **fmt))
			bw += __minus_dispatch(**fmt, buff, ap);
		free(buff);
		return (bw);
	}
	while (!ft_strchr("cspdiuxX%", **fmt))
		++(*fmt);
	if (ft_strchr("cspdiuxX", **fmt))
		bw += __spec_dispatch(**fmt, ap);
	return (bw);
}
