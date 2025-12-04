/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:09:28 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 20:47:08 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
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

int	get_chunk_size(int size)
{
	int	chunk;
	int	i;

	if (size <= 5)
		return (1);
	i = 0;
	while (i * i < size)
		i++;
	chunk = i * 14 / 10;
	if (chunk < 20)
		chunk = 20;
	return (chunk);
}
