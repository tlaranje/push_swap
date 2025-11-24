/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:36:55 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/24 14:44:31 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stk_a)
{
	push(stk_a, stk_a);
	ft_putstr_fd("ra ", 1);
	return (1);
}

int	rb(t_stack **stk_b)
{
	push(stk_b, stk_b);
	ft_putstr_fd("rb ", 1);
	return (1);
}

int	rr(t_stack **stk_a, t_stack **stk_b)
{
	push(stk_a, stk_a);
	push(stk_b, stk_b);
	ft_putstr_fd("rr ", 1);
	return (1);
}
