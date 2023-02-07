/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:54 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:55 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker_digit(char **args, int index, int dec)
{
	while (args[index])
	{
		while (args[index][dec])
		{
			if ((!ft_isdigit(args[index][dec])
				&& args[index][dec] != '-')
				|| (dec > 0 && args[index][dec] == '-'))
				return (0);
			dec++;
		}
		index++;
	}
	return (1);
}

static int	check_is_digit(char *argv[])
{
	int		argv_index;
	int		index;
	int		dec;
	char	**args;

	argv_index = 1;
	while (argv[argv_index])
	{
		index = 0;
		dec = 0;
		args = ft_split(argv[argv_index], ' ');
		if (!checker_digit(args, index, dec))
		{
			freeall(args);
			return (0);
		}
		freeall(args);
		argv_index++;
	}
	return (1);
}

static int	check_double_max_min(t_stack **stack, long int num)
{
	t_stack	*temp;
	int		times;

	temp = *stack;
	times = 0;
	if (num > MAX_INT || num < MIN_INT)
		return (0);
	while (temp)
	{
		if (temp->num == num)
			times++;
		if (times == 2)
			return (0);
		temp = temp->next;
	}
	temp = NULL;
	return (1);
}

static int	check_and_fill_stack(char **argv, t_stack **stack, t_info *info)
{
	char	**args;
	int		count_argv;
	int		count_args;

	count_argv = 1;
	while (argv[count_argv])
	{
		count_args = 0;
		args = ft_split(argv[count_argv], ' ');
		while (args[count_args])
		{
			ps_lstadd_back(stack, new_node(ft_long_atoi(args[count_args])));
			info->size_a++;
			if (!check_double_max_min(stack, ft_long_atoi(args[count_args])))
			{
				freeall(args);
				freelist(*stack);
				return (0);
			}
			count_args++;
		}
		freeall(args);
		count_argv++;
	}
	return (1);
}

int	checks(int argc, char *argv[], t_info *info)
{
	if (argc < 3)
		return (0);
	if (!check_is_digit(argv))
		return (print_error(ERROR));
	if (!check_and_fill_stack(argv, &info->temp, info))
		return (print_error(ERROR));
	return (1);
}
