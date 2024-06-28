/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:04:25 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/06/23 04:21:10 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstget_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	while (stack->next)
	{
		if (max < stack->next->data)
			max = stack->next->data;
		stack = stack->next;
	}
	return (max);
}

int	ft_lstgmin(t_stack *stack)
{
	int	min;

	min = stack->data;
	while (stack->next)
	{
		if (min > stack->next->data)
			min = stack->next->data;
		stack = stack->next;
	}
	return (min);
}

t_stack	*ft_lstbfr_last(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
