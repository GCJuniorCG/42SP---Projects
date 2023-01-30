/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:29:46 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:29:47 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoins(char *s1, char const *s2)
{
	char	*buff;
	size_t	size;

	if (!s1 || !*s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	buff = (char *)malloc(size + 1);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s1, -1);
	ft_strlcat(buff, s2, -1);
	free(s1);
	return (buff);
}
