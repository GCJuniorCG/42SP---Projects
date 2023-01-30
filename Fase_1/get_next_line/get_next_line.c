/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:36:48 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/30 16:58:51 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *left_str)
{
	char	*aux;
	int		read_b;

	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	read_b = 1;
	while (!ft_strchr(left_str, '\n') && read_b > 0)
	{
		read_b = read(fd, aux, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(aux);
			return (NULL);
		}
		aux[read_b] = '\0';
		left_str = ft_strjoin(left_str, aux);
	}
	free(aux);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = read_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_line(left_str);
	left_str = new_str(left_str);
	return (line);
}
