/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:32:48 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:32:50 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*store;
	t_list	*p;

	p = *lst;
	if (!p)
		return ;
	while (p)
	{
		store = p->next;
		ft_lstdelone(p, del);
		p = store;
	}
	*lst = NULL;
}
