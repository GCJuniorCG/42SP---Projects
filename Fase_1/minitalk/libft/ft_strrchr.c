/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:30:33 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:30:35 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_found;

	last_found = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_found = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_found);
}
