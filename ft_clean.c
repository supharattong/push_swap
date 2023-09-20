/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthongso <sthongso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:28:10 by sthongso          #+#    #+#             */
/*   Updated: 2023/09/14 21:23:22 by sthongso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean(t_node **stack)
{
	t_node	*temp;

	temp = NULL;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(stack);
}

void	ft_cleanstack(t_node **stack_a, t_node **stack_b, char **parg, int op)
{
	if (op)
	{
		ft_free(parg);
		ft_error(stack_a, stack_b);
	}
	ft_clean(stack_a);
	ft_clean(stack_b);
}

void	ft_error(t_node **stack_a, t_node **stack_b)
{
	ft_clean(stack_a);
	ft_clean(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
