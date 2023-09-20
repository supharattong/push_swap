/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:49:41 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/16 15:50:33 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_data(t_node **stack_a, int data)
{
	t_node	*node;
	t_node	*ptr;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(0);
	node->data = data;
	node->index = 0;
	node->next = NULL;
	if (*stack_a == NULL)
		*stack_a = node;
	else
	{
		ptr = *stack_a;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = node;
	}
}

void	add_node_front(t_node **stack, t_node *temp)
{
	if (temp == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = temp;
		(*stack)->next = NULL;
		return ;
	}
	temp->next = *stack;
	*stack = temp;
}

static int	skip_sp(char **parg, int i)
{
	int	j;

	j = 0;
	while (parg[i][j] == ' ' || ((parg[i][j] >= 9) && (parg[i][j] <= 13)))
		j++;
	return (j);
}

long	ft_atoi(char **parg, t_node **stack_a, t_node **stack_b, int i)
{
	long	sign;
	long	j;
	long	total;

	total = 0;
	sign = 1;
	j = skip_sp(parg, i);
	if (parg[i][j] == '+' || parg[i][j] == '-')
	{
		if (parg[i][j] == '-')
			sign = -1;
		j++;
		if (parg[i][j] < '0' || parg[i][j] > '9')
			ft_cleanstack(stack_a, stack_b, parg, 1);
	}
	while (parg[i][j])
	{
		if (parg[i][j] >= '0' && parg[i][j] <= '9')
			total = (total * 10) + (parg[i][j] - '0');
		else
			ft_cleanstack(stack_a, stack_b, parg, 1);
		j++;
	}
	return (sign * total);
}

void	ft_input(t_node **stack_a, t_node **stack_b, char **argv)
{
	char	**split_argv;
	int		i;
	int		j;
	long	number;

	i = 1;
	while (argv[i])
	{
		if ((!argv[i][0]) || (!ft_is_nspace(argv[i])))
			ft_error(stack_a, stack_b);
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv)
			ft_error(stack_a, stack_b);
		j = 0;
		while (split_argv[j])
		{
			number = ft_atoi(split_argv, stack_a, stack_b, j);
			if (number > 2147483647 || number < -2147483648)
				ft_cleanstack(stack_a, stack_b, split_argv, 1);
			add_node_data(stack_a, number);
			j++;
		}
		ft_free(split_argv);
		i++;
	}
}
