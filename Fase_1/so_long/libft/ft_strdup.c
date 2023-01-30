/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:07:30 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:08:21 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (*str)
		dest[i++] = *str++;
	dest[i] = '\0';
	return (dest);
}
