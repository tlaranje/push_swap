/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:37:50 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/19 16:47:30 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;
	t_stack	*last;

	last = *stack_2;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	ft_stack_add_front(stack_1, ft_stack_new(last->content));
	free(last);
}

int	rra(t_stack **stack_a)
{
	if (ft_stack_size(*stack_a) < 2)
		return (0);
	reverse_push(stack_a, stack_a);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack **stack_b)
{
	if (ft_stack_size(*stack_b) < 2)
		return (0);
	reverse_push(stack_b, stack_b);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_a) < 2))
		return (0);
	reverse_push(stack_a, stack_a);
	reverse_push(stack_b, stack_b);
	ft_putendl_fd("rrr", 1);
	return (1);
}
