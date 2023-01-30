/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:06:39 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:06:40 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux_str;

	aux_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (aux_str[i] == (unsigned char)c)
			return (&aux_str[i]);
		i++;
	}
	return (NULL);
}
