/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:17:10 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/02 16:53:14 by tlaranje         ###   ########.fr       */
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
	ft_printf("Num_chunks: %d\n\n", num_chunks);
	while (num_chunks > 0)
	{
		start_chunk = (num_chunks - 1) * chunk_size;
		end_chunk = start_chunk + chunk_size - 1;
		if (end_chunk >= stk_size)
			end_chunk = stk_size - 1;
		ft_printf("Chunk %d\n", num_chunks);
		ft_printf("Start_chunks: %d\n", start_chunk);
		ft_printf("End_chunks: %d\n\n", end_chunk);
		num_chunks--;
	}
	(void)stk_a;
	(void)stk_b;
	return (ops);
}
