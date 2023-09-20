/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:29:05 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/16 19:10:01 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	in_case_three(t_node **stack_a)
{
	if (((*stack_a)->data < (*stack_a)->next->next->data)
		&& ((*stack_a)->next->data > (*stack_a)->next->next->data))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->data))
		sa(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->data))
		rra(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->next->data < (*stack_a)->next->next->data))
		ra(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->next->data > (*stack_a)->next->next->data))
	{
		ra(stack_a);
		sa(stack_a);
	}
}

int	find_index_min(t_node **stack_a, int n)
{
	t_node	*current;
	int		i;

	current = *stack_a;
	i = 1;
	while (current)
	{
		if (current->index == n)
			break ;
		current = current->next;
		i++;
	}
	return (i);
}

void	in_case_four(t_node **stack_a, t_node **stack_b)
{
	int	n;

	n = find_index_min(stack_a, find_minindex_position(stack_a));
	if (n == 1)
		pb(stack_a, stack_b);
	else if (n == 2)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (n == 3)
	{
		ra(stack_a);
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	in_case_three(stack_a);
	pa(stack_a, stack_b);
}

void	in_case_five(t_node **stack_a, t_node **stack_b, int n)
{
	if (n == 2)
		ra(stack_a);
	else if (n == 3)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (n == 4)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else
		rra(stack_a);
	pb(stack_a, stack_b);
	in_case_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_simple_sort(t_node **stack_a, t_node **stack_b, int i)
{
	int	n;

	if (ft_check_sortdata(stack_a))
	{
		if (i == 1)
			return ;
		else if (i == 2)
			sa(stack_a);
		else if (i == 3)
			in_case_three(stack_a);
		else if (i == 4)
			in_case_four(stack_a, stack_b);
		else if (i == 5)
		{
			n = find_index_min(stack_a, 1);
			if (n == 1)
			{
				pb(stack_a, stack_b);
				in_case_four(stack_a, stack_b);
				pa(stack_a, stack_b);
			}
			else
				in_case_five(stack_a, stack_b, n);
		}
	}
}
