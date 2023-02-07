/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:42 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 23:41:22 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int error)
{
	char	*message[1];

	message[ERROR] = "Error\n";
	ft_putstr_fd(message[error], 2);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	initializing_stack(&info);
	if (!checks(argc, argv, &info))
		return (1);
	bubble_sort(&info);
	freelist(info.temp);
	if (order_check(&info.stack_a))
	{
		freelist(info.stack_a);
		return (0);
	}
	if (info.size_a <= 5)
		small_sort(&info);
	else
		big_sort(&info);
	freelist(info.stack_a);
	return (0);
}
