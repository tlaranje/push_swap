/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:36:17 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/19 16:47:13 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (ft_stack_size(*stack_2) == 0)
		return (0);
	ft_stack_add_back(stack_1, ft_stack_new((*stack_2)->content));
	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	free(tmp);
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_b) == 0)
		return (0);
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) == 0)
		return (0);
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
	return (1);
}
