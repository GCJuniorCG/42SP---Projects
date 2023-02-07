/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:38 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:39 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

enum e_errors {
	ERROR,
};

enum e_prints {
	sa,
	sb,
	ra,
	rb,
	rra,
	rrb
};

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;
	int		size_a;
	int		size_b;
	int		group_size;
	int		groups;
	int		rest;
}	t_info;

//clean
void	freeall(char **s);
void	freelist(t_stack *stack);

//stacks
void	initializing_stack(t_info *info);
int		checks(int argc, char *argv[], t_info *info);
t_stack	*new_node(long int num);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
void	del_first_node(t_stack **stack);
void	del_last(t_stack **stack);
t_stack	*ps_lstlast(t_stack *lst);
void	bubble_sort(t_info *info);
int		order_check(t_stack **stack);

//instructions
void	swap(t_stack **stack, int print);
void	swap_s(t_info *info);

void	push_a_to_b(t_info *info);
void	push_b_to_a(t_info *info);

void	rotate(t_stack **stack, int print);
void	rotate_r(t_info *stacks);

void	reverse_rotate(t_stack **stack, int print);
void	reverse_rotate_r(t_info *info);

//small sort
void	small_sort(t_info *info);
void	five_elements(t_info *info);
void	send_smallest(t_info *info);

void	big_sort(t_info *info);
int		find_algoritmo(t_stack **stack);
int		find_biggest(t_stack **stack, int *biggest);
void	send_rest_to_b(t_info *info);
void	organize_b(t_info *info);

//for small or big sorts
int		rotate_or_reverse(int size, int position);
void	to_b(t_info *info, int num, int decision);
void	to_b(t_info *info, int num, int decision);
void	to_a(t_info *info, int num, int decision);
int		print_error(int error);

#endif
