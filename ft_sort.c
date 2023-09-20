/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:42:37 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/13 17:42:57 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*pre_node;
	t_node	*ptr;

	ptr = *stack_a;
	pre_node = ptr->next;
	ptr->next = pre_node->next;
	pre_node->next = ptr;
	*stack_a = pre_node;
	write(1, "sa\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	add_node_front(stack_a, temp);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	add_node_front(stack_b, temp);
	write(1, "pb\n", 3);
}

void	ra(t_node **stack_a)
{
	t_node	*ptr;

	ptr = *stack_a;
	*stack_a = (*stack_a)->next;
	ptr->next = NULL;
	add_node_back(stack_a, ptr);
	write(1, "ra\n", 3);
}

void	rra(t_node **stack_a)
{
	t_node	*ptr;
	t_node	*current;

	ptr = *stack_a;
	current = *stack_a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	while (current->next != ptr)
		current = current->next;
	current->next = NULL;
	add_node_front(stack_a, ptr);
	write(1, "rra\n", 4);
}
