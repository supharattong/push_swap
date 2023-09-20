/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:17:47 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/16 18:40:42 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_of_nodes(t_node **stack_a)
{
	int		count;
	t_node	*ptr;

	count = 0;
	ptr = NULL;
	if (*stack_a == NULL)
		return (0);
	ptr = *stack_a;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

void	ft_checkdup(t_node **stack_a, t_node **stack_b)
{
	t_node	*ptr;
	t_node	*current;

	ptr = *stack_a;
	while (ptr != NULL)
	{
		current = ptr->next;
		while (current != NULL)
		{
			if (current->data == ptr->data)
				ft_error(stack_a, stack_b);
			current = current->next;
		}
		ptr = ptr->next;
	}
}

int	ft_check_sortdata(t_node **stack_a)
{
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr->next != NULL)
	{
		if (ptr->index < ptr->next->index)
			ptr = ptr->next;
		else
			return (1);
	}
	return (0);
}

int	ft_is_nspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	find_minindex_position(t_node **stack_a)
{
	t_node	*min;
	t_node	*ptr;

	min = *stack_a;
	ptr = *stack_a;
	while (ptr->next)
	{
		if (min->index > ptr->next->index)
			min = ptr->next;
		ptr = ptr->next;
	}
	return (min->index);
}
