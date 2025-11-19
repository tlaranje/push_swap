/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:35 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/19 16:49:53 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_is_sort(t_stack *stack)
{
	t_stack	*stack1;
	t_stack	*stack2;

	stack1 = stack;
	while (stack1)
	{
		stack2 = stack1->next;
		while (stack2)
		{
			if (stack1->content > stack2->content)
				return (0);
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
	return (1);
}

/* static int	ft_find_max(t_stack *stack)
{
	(void)stack;
	return (0);
} */

int	ft_sort(t_stack **stack)
{
	int	max;

	if (ft_check_is_sort(*stack))
		return (1);
	max = ft_stack_size(*stack);
	printf("Size: %d\n", max);
	return (0);
}