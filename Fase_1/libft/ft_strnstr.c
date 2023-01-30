/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:00:38 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/22 01:28:27 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	n2;

	if (*s2 == '\0')
		return ((char *)s1);
		
	n2 = ft_strlen((char *)s2);
	while (*s1 != '\0' && n-- >= n2)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, n2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
