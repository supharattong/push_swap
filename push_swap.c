/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:28:53 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/16 18:13:31 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stack(t_node **stack_a, t_node **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		exit(0);
	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	if (!stack_a)
		exit(0);
	if (!stack_b)
		exit(0);
	set_stack(stack_a, stack_b);
	ft_input(stack_a, stack_b, argv);
	ft_checkdup(stack_a, stack_b);
	add_index(stack_a);
	ft_check_sortdata(stack_a);
	ft_simple_radix(stack_a, stack_b);
	ft_cleanstack(stack_a, stack_b, NULL, 0);
}
