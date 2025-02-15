/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:18:04 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/06/24 00:18:04 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if (((*stack)->data > (*stack)->next->data))
		swap(stack, "sa");
}

void	sort_3(t_stack **stack)
{
	if ((*stack)->data == ft_lstget_max(*stack))
		rotate(stack, "ra");
	if ((*stack)->next->data == ft_lstget_max(*stack))
		r_rotate(stack, "rra");
	if ((*stack)->data > (*stack)->next->data)
		swap(stack, "sa");
}

t_stack	*find_value(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	sort_5(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (ft_lstsize(*stack_a) > 3)
	{
		last_rotat(stack_a, find_value(*stack_a, ft_lstgmin(*stack_a)), 'a');
		push(stack_a, &stack_b, "pb");
	}
	sort_3(stack_a);
	push(&stack_b, stack_a, "pa");
	push(&stack_b, stack_a, "pa");
}

void	push_swap(t_stack **a, int chunksize)
{
	t_stack	*b;

	b = NULL;
	push_to_b(a, &b, chunksize);
	push_to_a(a, &b);
}
