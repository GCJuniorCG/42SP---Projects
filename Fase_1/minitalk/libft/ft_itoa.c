/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:23:51 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:23:52 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_CHARS 10

static char	*copy_from_buffer(char *buffer, int end_pos, int is_negative)
{
	int		idx;
	char	*result;

	idx = 0;
	result = (char *)malloc((end_pos + is_negative + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (is_negative)
	{
		result[idx++] = '-';
	}
	while (end_pos-- > 0)
	{
		result[idx++] = buffer[end_pos];
	}
	result[idx] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	buffer[MAX_CHARS];
	int		end_pos;
	int		is_negative;

	end_pos = 0;
	is_negative = 0;
	if (n == 0)
		buffer[end_pos++] = '0';
	else
	{
		if (n > 0)
			n = -n;
		else
			is_negative = 1;
		while (n != 0)
		{
			buffer[end_pos++] = '0' - n % 10;
			n /= 10;
		}
	}
	return (copy_from_buffer(buffer, end_pos, is_negative));
}
