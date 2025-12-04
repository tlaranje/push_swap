/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:36:55 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 23:31:52 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stk)
{
	t_stack	*first;

	if (!*stk || !(*stk)->next)
		return (0);
	first = *stk;
	*stk = first->next;
	first->next = NULL;
	ft_stack_add_back(stk, first);
	return (1);
}

int	ra(t_stack **stk_a)
{
	if (rotate(stk_a))
		ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stk_b)
{
	if (rotate(stk_b))
		ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **stk_a, t_stack **stk_b)
{
	int	rot_a;
	int	rot_b;

	rot_a = rotate(stk_a);
	rot_b = rotate(stk_b);
	if (rot_a || rot_b)
		ft_printf("rr\n");
	return (rot_a || rot_b);
}
