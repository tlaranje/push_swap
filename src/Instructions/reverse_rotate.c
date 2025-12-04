/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:37:50 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 23:31:40 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack **stk)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stk || !(*stk)->next)
		return (0);
	prev = NULL;
	last = *stk;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ft_stack_add_front(stk, last);
	return (1);
}

int	rra(t_stack **stk_a)
{
	if (reverse_rotate(stk_a))
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stk_b)
{
	if (reverse_rotate(stk_b))
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **stk_a, t_stack **stk_b)
{
	int	rev_a;
	int	rev_b;

	rev_a = reverse_rotate(stk_a);
	rev_b = reverse_rotate(stk_b);
	if (rev_a || rev_b)
		ft_printf("rrr\n");
	return (rev_a || rev_b);
}
