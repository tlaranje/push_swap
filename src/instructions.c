/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:20:43 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/18 16:58:09 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list *lst_swap)
{
	t_list	*lst_1;
	t_list	*lst_2;
 	int tmp;

	if (ft_lstsize(lst_swap) < 2)
		return (0);
	lst_1 = lst_swap;
	lst_2 = lst_swap->next;
	tmp = *(int *)lst_1->content;
	*(int *)lst_1->content = *(int *)lst_2->content;
	*(int *)lst_2->content = tmp;
	return (1);
}

int	sa(t_list *lst_a)
{
	if (swap(lst_a) == 0)
		return (0);
	return (1);
}

int	sb()
{
	return (0);
}

int	ss()
{
	return (0);
}

int	pa()
{
	return (0);
}

int	pb()
{
	return (0);
}

int	ra()
{
	return (0);
}

int	rb()
{
	return (0);
}

int	rr()
{
	return (0);
}

int	rra()
{
	return (0);
}

int	rrb()
{
	return (0);
}

int	rrr()
{
	return (0);
}