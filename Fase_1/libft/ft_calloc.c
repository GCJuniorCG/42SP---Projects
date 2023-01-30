/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:23:11 by gcamargo          #+#    #+#             */
/*   Updated: 2022/06/15 19:51:57 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*cllc;
	int		result;

	if (cnt == 0 || n == 0)
		return (NULL);
	result = (cnt * n);
	if (result / cnt != n)
		return (NULL);
	cllc = malloc(n * cnt);
	if (!cllc)
		return (NULL);
	ft_bzero(cllc, n * cnt);
	return (cllc);
}
