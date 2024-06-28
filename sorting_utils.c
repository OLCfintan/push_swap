/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:04:43 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/06/24 00:10:21 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int_tab(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
	}
	return (arr);
}

int	*list_to_arr(t_stack *stack)
{
	int	*arr;
	int	i;
	int	size;

	size = ft_lstsize(stack);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
	return (sort_int_tab(arr, size));
}

void	update_position(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_median = (i <= median);
		stack = stack->next;
		i++;
	}
}

void	last_rotat(t_stack **stack, t_stack *top, char c)
{
	if (!top)
		return ;
	update_position(*stack);
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->above_median == 1)
				rotate(stack, "ra");
			else
				r_rotate(stack, "rra");
		}
		else if (c == 'b')
		{
			if (top->above_median == 1)
				rotate(stack, "rb");
			else
				r_rotate(stack, "rrb");
		}
	}
}
