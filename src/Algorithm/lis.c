/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:58:42 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 17:18:21 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lis(t_stack **stk_a)
{
	t_stack	*cur;
	t_stack	*prev;
	int		max_lis;

	max_lis = 0;
	cur = *stk_a;
	while (cur)
	{
		prev = *stk_a;
		cur->lis_length = 1;
		while (prev != cur)
		{
			if (prev->content < cur->content
				&& prev->lis_length + 1 > cur->lis_length)
				cur->lis_length = prev->lis_length + 1;
			prev = prev->next;
		}
		if (cur->lis_length > max_lis)
			max_lis = cur->lis_length;
		cur = cur->next;
	}
	return (max_lis);
}

void	set_is_lis(t_stack **stk_a, int max_len)
{
	t_stack	*cur;
	t_stack *tmp;
	t_stack *res;

	cur = NULL;
	while (max_len > 0)
	{
		tmp = *stk_a;
		res = NULL;
		while (tmp)
		{
			 if (tmp->lis_length == max_len
				&& (!cur || tmp->content <= cur->content))
				if (!res)
					res = tmp;
			tmp = tmp->next;
		}
		if (!res) break;
		res->is_lis = 1;
		cur = res;
		max_len--;
	}
}

/* void	move_lis(t_stack **stk_a, t_stack **stk_b, int stk_size, int *ops)
{
	t_stack	*tmp;
	int lis_count;
	int max_lis;

	lis_count = 0;
	tmp = *stk_a;
	while (tmp)
	{
		tmp->lis_length = 1;
		tmp = tmp->next;
	}
	max_lis = lis(stk_a);
	set_is_lis(stk_a, lis(stk_a));
	while (stk_size-- && lis_count < max_lis)
	{
		if ((*stk_a)->is_lis == 1)
			*ops += ra(stk_a);
		else
		{
			*ops += pb(stk_a, stk_b);
			lis_count++;
		}
	}
} */

void	move_lis(t_stack **stk_a, t_stack **stk_b, int stk_size, int *ops)
{
	t_stack	*tmp;

	tmp = *stk_a;
	while (tmp)
	{
		tmp->lis_length = 1;
		tmp = tmp->next;
	}
	 lis(stk_a);
	set_is_lis(stk_a, lis(stk_a));
	while (stk_size--)
	{
		if ((*stk_a)->is_lis == 1)
			*ops += ra(stk_a);
		else
			*ops += pb(stk_a, stk_b);
	}
}
