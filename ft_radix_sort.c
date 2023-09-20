/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:16:27 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/15 21:33:52 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_max(t_node **stack_a)
{
	int	i;
	int	count;

	i = 0;
	count = count_of_nodes(stack_a);
	while ((count >> i) != 0)
		i++;
	return (i);
}

void	ft_radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		bit;
	int		i;
	int		countnode;
	t_node	*ptr;

	i = 0;
	bit = bit_max(stack_a);
	while (i < bit && ft_check_sortdata(stack_a))
	{
		countnode = count_of_nodes(stack_a);
		while (countnode--)
		{
			ptr = *stack_a;
			if ((ptr->index & (1 << i)))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		countnode = count_of_nodes(stack_b);
		while (countnode--)
			pa(stack_a, stack_b);
		i++;
	}
}
