/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:09:28 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/24 13:59:18 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
}

int	ft_is_sort(t_stack *stk_a)
{
	t_stack	*stk_b;

	while (stk_a)
	{
		stk_b = stk_a->next;
		while (stk_b)
		{
			if (stk_a->content > stk_b->content)
				return (0);
			stk_b = stk_b->next;
		}
		stk_a = stk_a->next;
	}
	return (1);
}

int	ft_max(t_stack *stk_a)
{
	int	max;
	int	nbr;

	max = stk_a->content;
	while (stk_a)
	{
		nbr = stk_a->content;
		if (nbr > max)
			max = stk_a->content;
		stk_a = stk_a->next;
	}
	return (max);
}

int	ft_min_pos(t_stack *stk_a)
{
	int	min;
	int	pos;
	int	i;

	min = stk_a->content;
	pos = 0;
	i = 0;
	while (stk_a)
	{
		if (stk_a->content < min)
		{
			min = stk_a->content;
			pos = i;
		}
		stk_a = stk_a->next;
		i++;
	}
	return (pos);
}
