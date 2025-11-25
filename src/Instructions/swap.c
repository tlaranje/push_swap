/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:20:43 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/25 12:02:27 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stk_swap)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		tmp;

	if (ft_stack_size(*stk_swap) < 2)
		return (0);
	stk_a = *stk_swap;
	stk_b = (*stk_swap)->next;
	tmp = stk_a->content;
	stk_a->content = stk_b->content;
	stk_b->content = tmp;
	return (1);
}

int	sa(t_stack **stk_a)
{
	if (swap(stk_a) == 0)
		return (0);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **stk_b)
{
	if (swap(stk_b) == 0)
		return (0);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_stack **stk_a, t_stack **stk_b)
{
	if (swap(stk_a) == 0)
		return (0);
	if (swap(stk_b) == 0)
		return (0);
	ft_printf("ss\n");
	return (1);
}
