/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:36:17 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/24 15:58:59 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp;

	if (!*stk_b)
		return (0);
	tmp = *stk_b;
	*stk_b = (*stk_b)->next;
	tmp->next = *stk_a;
	*stk_a = tmp;
	return (1);
}

int	pa(t_stack **stk_a, t_stack **stk_b)
{
	if (ft_stack_size(*stk_b) == 0)
		return (0);
	push(stk_a, stk_b);
	ft_putstr_fd("pa ", 1);
	return (1);
}

int	pb(t_stack **stk_a, t_stack **stk_b)
{
	if (ft_stack_size(*stk_a) == 0)
		return (0);
	push(stk_b, stk_a);
	ft_putstr_fd("pb ", 1);
	return (1);
}
