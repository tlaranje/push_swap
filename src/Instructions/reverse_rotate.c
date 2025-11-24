/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:37:50 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/24 14:44:07 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_push(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp;
	t_stack	*last;

	last = *stk_b;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	ft_stack_add_front(stk_a, ft_stack_new(last->content));
	free(last);
}

int	rra(t_stack **stk_a)
{
	if (ft_stack_size(*stk_a) < 2)
		return (0);
	reverse_push(stk_a, stk_a);
	ft_putstr_fd("rra ", 1);
	return (1);
}

int	rrb(t_stack **stk_b)
{
	if (ft_stack_size(*stk_b) < 2)
		return (0);
	reverse_push(stk_b, stk_b);
	ft_putstr_fd("rrb ", 1);
	return (1);
}

int	rrr(t_stack **stk_a, t_stack **stk_b)
{
	if ((ft_stack_size(*stk_a) < 2) || (ft_stack_size(*stk_a) < 2))
		return (0);
	reverse_push(stk_a, stk_a);
	reverse_push(stk_b, stk_b);
	ft_putstr_fd("rrr ", 1);
	return (1);
}
