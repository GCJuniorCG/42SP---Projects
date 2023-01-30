/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:10:43 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:10:45 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*aux_str;

	len = ft_strlen(s);
	aux_str = (unsigned char *)s + len - 1;
	if ((unsigned char)c == '\0')
		return ((char *)s + len);
	while (len--)
	{
		if (*aux_str == (unsigned char)c)
			return ((char *)aux_str);
		aux_str--;
	}
	return (NULL);
}
