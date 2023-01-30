/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:25:24 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:25:25 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n != 0 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}
