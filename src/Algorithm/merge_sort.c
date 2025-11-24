/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:35 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/24 16:52:49 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//merge_sort(stk_a, 0, ft_stack_size(*stk_a) - 1);

int	merge(t_stack **stk_a, int left, int midle, int right)
{
	t_stack *stk_1;
	t_stack *stk_2;
	t_stack *tmp;
	int i;
	(void)right;
	(void)left;
	i = 0;
	stk_1 = *stk_a;
	stk_2 = *stk_a;
	i = midle + 1;
	while (i-- > 0 && stk_2)
		stk_2 = stk_2->next;
	tmp = *stk_a;
	i = midle;
	while (i-- > 0 && tmp)
		tmp = tmp->next;
	if (tmp)
		tmp->next = NULL;
	i = 0;
	printf("stk_1\n");
	while (stk_1)
	{
		printf("    %d: %d\n", i, stk_1->content);
		stk_1 = stk_1->next;
		i++;
	}
	i = 0;
	printf("stk_2\n");
	while (stk_2)
	{
		printf("    %d: %d\n", i, stk_2->content);
		stk_2 = stk_2->next;
		i++;
	}
	return (0);
}

int	merge_sort(t_stack **stk_a, int left, int right)
{
	int	midle;
	(void)stk_a;

	if (left < right)
	{
		midle = left + (right - left) / 2;
		/* merge_sort(stk_a, left, midle);
		merge_sort(stk_a, midle + 1, right); */
		merge(stk_a, left, midle, right);
	}
	return (0);
}
