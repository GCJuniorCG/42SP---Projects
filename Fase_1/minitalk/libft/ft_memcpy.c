/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:25:29 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:25:31 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (src == NULL && dest == NULL && n != 0)
		return (dest);
	while (n-- != 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
