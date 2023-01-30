/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:28:14 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:28:16 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__ndigits(unsigned long n, char *base)
{
	int	d;

	d = 0;
	if (n < ft_strlen(base))
		return (1);
	while (n)
	{
		n /= ft_strlen(base);
		d++;
	}
	return (d);
}

char	*ft_ultoa(unsigned long n, char *base)
{
	int		len;
	char	*s;

	if (!base || !*base)
		base = "0123456789";
	len = ft__ndigits(n, base);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (--len)
	{
		s[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	s[len] = base[n % ft_strlen(base)];
	return (s);
}
