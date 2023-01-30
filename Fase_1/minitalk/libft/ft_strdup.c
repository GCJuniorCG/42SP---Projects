/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:29:20 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:29:21 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*copy;

	len_s = ft_strlen(s) + 1;
	copy = malloc(len_s * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s, len_s);
	return (copy);
}
