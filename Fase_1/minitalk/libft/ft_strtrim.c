/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:30:40 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:30:41 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	charmap[256];
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	if (set == NULL)
		return (ft_strdup(s1));
	ft_bzero(charmap, 256);
	while (*set != '\0')
	{
		charmap[(int)(*set)] = 1;
		set++;
	}
	start = 0;
	while (charmap[(int)(s1[start])])
		start++;
	end = ft_strlen(s1) - 1;
	while (charmap[(int)(s1[end])] && end > start)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
