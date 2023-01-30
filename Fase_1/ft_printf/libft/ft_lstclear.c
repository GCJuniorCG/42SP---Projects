/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:05:34 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:05:36 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux_free;

	if (*lst && del && lst)
	{
		while (*lst)
		{
			aux_free = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = aux_free;
		}
		*lst = NULL;
	}
}
