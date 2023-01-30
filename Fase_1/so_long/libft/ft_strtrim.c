/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:28:48 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:28:50 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__setoff(const char *set, const char ch)
{
	while (*set)
		if ((unsigned char)ch == (unsigned char)*set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*last;

	last = s1 + (ft_strlen(s1) - 1);
	while (ft__setoff(set, *s1))
		s1++;
	while (ft__setoff(set, *last))
		last--;
	if (s1 > last)
		return (ft_strdup(""));
	return (ft_substr(s1, 0, (last - s1) + 1));
}
