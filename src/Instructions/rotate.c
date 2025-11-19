/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:36:55 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/19 16:47:39 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a)
{
	push(stack_a, stack_a);
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_stack **stack_b)
{
	push(stack_b, stack_b);
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_a);
	push(stack_b, stack_b);
	ft_putendl_fd("rr", 1);
	return (1);
}
