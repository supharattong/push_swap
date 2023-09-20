/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:42:08 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/14 21:22:42 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_node **stack, t_node *ptr)
{
	t_node	*back;

	if (ptr == NULL)
		return ;
	else
	{
		back = *stack;
		while (back->next)
			back = back->next;
		back->next = ptr;
	}
}

void	ft_simple_radix(t_node **stack_a, t_node **stack_b)
{
	if (count_of_nodes(stack_a) < 6)
		ft_simple_sort(stack_a, stack_b, count_of_nodes(stack_a));
	else
		ft_radix_sort(stack_a, stack_b);
}

void	add_index(t_node **stack_a)
{
	int		i;
	t_node	*loop;
	t_node	*current;

	loop = *stack_a;
	while (loop)
	{
		current = *stack_a;
		i = 1;
		while (current)
		{
			if (current->data < loop->data)
				i++;
			current = current->next;
		}
		loop->index = i;
		loop = loop->next;
	}
}
