/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:09:28 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 11:08:14 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
}

int	ft_min_index(t_stack *a)
{
	int	min;

	min = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}

int	ft_max_index(t_stack *a)
{
	int	max;

	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

void	add_index(t_stack **stk_a)
{
	t_stack	*n1;
	t_stack	*n2;
	int		i;

	i = 0;
	n1 = *stk_a;
	while (n1)
	{
		i = 0;
		n2 = *stk_a;
		while (n2)
		{
			if (n1->content > n2->content)
				i++;
			n2 = n2->next;
		}
		n1->index = i;
		n1 = n1->next;
	}
}
