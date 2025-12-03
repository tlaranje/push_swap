/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:44:09 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 10:38:32 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*new_stk;

	new_stk = malloc(sizeof(t_stack));
	if (!new_stk)
		return (NULL);
	new_stk->content = content;
	new_stk->next = NULL;
	return (new_stk);
}

void	ft_stack_add_front(t_stack **stk, t_stack *new_stk)
{
	new_stk->next = *stk;
	*stk = new_stk;
}

void	ft_stack_add_back(t_stack **stk, t_stack *new_stk)
{
	t_stack	*last;

	if (*stk == NULL)
	{
		*stk = new_stk;
		return ;
	}
	last = *stk;
	while (last->next)
		last = last->next;
	last->next = new_stk;
}

void	ft_stack_clear(t_stack **stk)
{
	t_stack	*new_stk;

	if (!stk || !*stk)
		return ;
	while (*stk)
	{
		new_stk = (*stk)->next;
		free(*stk);
		*stk = new_stk;
	}
	*stk = NULL;
}

int	ft_stack_size(t_stack *stk)
{
	size_t	len;

	len = 0;
	while (stk)
	{
		len++;
		stk = stk->next;
	}
	return (len);
}
