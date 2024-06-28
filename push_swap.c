/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:04:29 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/06/28 21:43:49 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head;

	if (ac == 1)
		ft_perror(0, NULL);
	head = check_args(ac, av);
	if (!head)
		ft_perror(1, "Error\n");
	if (!ft_islst_sorted(&head))
	{
		if (ft_lstsize(head) == 2)
			sort_2(&head);
		else if (ft_lstsize(head) == 3)
			sort_3(&head);
		else if (ft_lstsize(head) <= 5)
			sort_5(&head);
		else if (ft_lstsize(head) <= 100)
			push_swap(&head, 15);
		else if (ft_lstsize(head) > 100)
			push_swap(&head, 30);
	}
	ft_lstclear(&head);
}
