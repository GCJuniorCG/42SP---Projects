/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:06:29 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:06:42 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_buff(int fd)
{
	char	*buff;
	char	*slice;
	int		*bytes_transfer;
	int		bytes_read;

	if (BUFFER_SIZE < 0)
		return (NULL);
	bytes_transfer = malloc(BUFFER_SIZE * sizeof(int *));
	*bytes_transfer = BUFFER_SIZE;
	buff = malloc(BUFFER_SIZE * sizeof(char *) + 1);
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, *bytes_transfer);
	free(bytes_transfer);
	if (bytes_read < 1)
	{
		free(buff);
		return (NULL);
	}
	buff[bytes_read] = '\0';
	slice = ft_strdup(buff);
	free(buff);
	return (slice);
}
