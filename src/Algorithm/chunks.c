/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:17:10 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/02 16:39:29 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunks_sort(t_stack **stk_a, t_stack **stk_b, int chunk_size, int stk_size)
{
	int	ops;
	int	num_chunks;
	int	start_chunk;
	int	end_chunk;

	num_chunks = (stk_size + chunk_size - 1) / chunk_size;
	ops = 0;
	while (num_chunks--)
	{
		//start_chunk =
	}
	(void)stk_a;
	(void)stk_b;
	return (ops);
}