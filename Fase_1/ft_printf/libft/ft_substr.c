/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:11:03 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:11:06 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size_s;
	size_t	size_max;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (size_s < start)
		return (ft_strdup(""));
	if (size_s - start <= len)
		size_max = size_s - start + 1;
	else
		size_max = len + 1;
	sub = (char *)malloc(sizeof(char) * (size_max));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, size_max);
	return (sub);
}
