/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:06:28 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:06:29 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux_lst;
	int		len;

	aux_lst = lst;
	len = 0;
	while (aux_lst)
	{
		aux_lst = aux_lst->next;
		len++;
	}
	return (len);
}
