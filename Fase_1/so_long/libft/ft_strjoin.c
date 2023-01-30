/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:29:52 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:29:54 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	buff = (char *)malloc(size + 1);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s1, -1);
	ft_strlcat(buff, s2, -1);
	return (buff);
}
