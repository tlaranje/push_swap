/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:09:28 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/25 16:52:38 by tlaranje         ###   ########.fr       */
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
