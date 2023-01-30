/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:09:05 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:09:06 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*aux_str;

	aux_str = (char *)str;
	while (*aux_str)
	{
		if (*aux_str == (char)c)
			return (aux_str);
		aux_str++;
	}
	if (c == '\0')
		return (aux_str);
	return (NULL);
}
