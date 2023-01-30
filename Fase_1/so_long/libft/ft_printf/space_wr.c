/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_wr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:36:25 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:36:27 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	__space_c(char *buff, va_list ap)
{
	char	*temp;
	int		bw;

	temp = ft_calloc(ft_strlen(buff) + 1, sizeof(char));
	ft_memcpy(temp, buff, ft_strlen(buff));
	temp[ft_strlen(temp) - 1] = va_arg(ap, int);
	bw = ft_putstr(temp);
	free(temp);
	return (bw);
}

int	__space_spx(char *buff, char *s)
{
	size_t	delta;
	char	*temp;
	int		bw;

	delta = ft_strlen(buff) - ft_strlen(s);
	temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
	ft_memcpy(temp, buff, delta);
	ft_strlcat(temp, s, -1);
	bw = ft_putstr(temp);
	free(temp);
	return (bw);
}

int	__space_uid(char *buff, char *s)
{
	size_t	delta;
	char	*temp;
	int		bw;

	delta = ft_strlen(buff) - ft_strlen(s);
	temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
	ft_memcpy(temp, buff, delta);
	ft_strlcat(temp, s, -1);
	bw = ft_putstr(temp);
	free(temp);
	free(s);
	return (bw);
}
