/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:09:28 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/21 16:24:16 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
}

int	ft_is_sort(t_stack *stack)
{
	t_stack	*stack1;
	t_stack	*stack2;

	stack1 = stack;
	while (stack1)
	{
		stack2 = stack1->next;
		while (stack2)
		{
			if (stack1->content > stack2->content)
				return (0);
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
	return (1);
}

int	ft_max(t_stack *stack)
{
	int	max;
	int	nbr;

	max = stack->content;
	while (stack)
	{
		nbr = stack->content;
		if (nbr > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}