/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:04:07 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/06/24 00:04:38 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int data)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
	{
		free(lst);
		return (NULL);
	}
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*curr;
	t_stack	*next;

	if (!lst || !(*lst))
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

int	ft_islst_sorted(t_stack **stack)
{
	t_stack	*curr;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	curr = *stack;
	while (curr->next)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}
