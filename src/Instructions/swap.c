/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:20:43 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/19 16:47:49 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack_swap)
{
	t_stack	*stack_1;
	t_stack	*stack_2;
	int		tmp;

	if (ft_stack_size(*stack_swap) < 2)
		return (0);
	stack_1 = *stack_swap;
	stack_2 = (*stack_swap)->next;
	tmp = stack_1->content;
	stack_1->content = stack_2->content;
	stack_2->content = tmp;
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (swap(stack_a) == 0)
		return (0);
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_stack **stack_b)
{
	if (swap(stack_b) == 0)
		return (0);
	ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_a) == 0)
		return (0);
	if (swap(stack_b) == 0)
		return (0);
	ft_putendl_fd("ss", 1);
	return (1);
}
