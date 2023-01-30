/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:06:48 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:06:50 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*aux_str1;
	unsigned char	*aux_str2;

	aux_str1 = (unsigned char *)str1;
	aux_str2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (aux_str1[i] != aux_str2[i])
			return (aux_str1[i] - aux_str2[i]);
		i++;
	}
	return (0);
}
