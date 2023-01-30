/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:09:04 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:09:44 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_append(char *s1, char c)
{
	int		i;
	char	*m;

	if (!s1 || !c)
		return (NULL);
	m = malloc((ft_strlen(s1) + sizeof(c)) + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = c;
	i++;
	m[i] = '\0';
	free(s1);
	return (m);
}
