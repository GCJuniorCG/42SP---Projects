/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:29:38 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:29:39 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*src_start;
	const char	*dst_start;
	size_t		dst_length;

	src_start = src;
	dst_start = dst;
	while (size != 0 && *dst != '\0')
	{
		dst++;
		size--;
	}
	dst_length = dst - dst_start;
	if (size == 0)
		return (ft_strlen(src) + dst_length);
	while (*src != '\0')
	{
		if (size != 1)
		{
			*dst++ = *src;
			size--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_length + src - src_start);
}
