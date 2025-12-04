/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/04 00:20:05 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

//=== Stack ===
typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

//=== Stack Utils ===
t_stack	*ft_stack_new(int content);
void	ft_stack_add_front(t_stack **stk, t_stack *new_stk);
void	ft_stack_add_back(t_stack **stk, t_stack *new_stk);
void	ft_stack_clear(t_stack **stk);
int		ft_stack_size(t_stack *stk);

//=== Check args ===
int		ft_check_args(int ar, char *av[], t_stack **stk);
long	ft_atol(const char *str);
int		is_in_range_of_int(char *str);

//=== Instructions ===
//Swap
int		swap(t_stack **stk_swap);
int		sa(t_stack **stk_a);
int		sb(t_stack **stk_b);
int		ss(t_stack **stk_a, t_stack **stk_b);

//Push
int		push(t_stack **stk_a, t_stack **stk_b);
int		pa(t_stack **stk_a, t_stack **stk_b);
int		pb(t_stack **stk_a, t_stack **stk_b);

//Rotate
int		ra(t_stack **stk_a);
int		rb(t_stack **stk_b);
int		rr(t_stack **stk_a, t_stack **stk_b);

//Reverse Rotate
int		rra(t_stack **stk_a);
int		rrb(t_stack **stk_b);
int		rrr(t_stack **stk_a, t_stack **stk_b);

//=== Algorithm ===
//Small Sort
int		sort_2(t_stack **stk_a);
int		sort_3(t_stack **stk_a);
int		sort_4(t_stack **stk_a, t_stack **stk_b);
int		sort_5(t_stack **stk_a, t_stack **stk_b);

//Radix Sort
int		radix_sort(t_stack **stk_a, t_stack **stk_b, int stk_size);
void	add_index(t_stack **stk_a);

//Chunk Sort
int		chunks_sort(t_stack **stk_a, t_stack **stk_b, int c_size, int s_size);
int		get_chunk_size(int size);
int		find_target_index(t_stack *stk_a, int start, int end);
int		find_max_index(t_stack *stk_b);
int		rotate_to_top(t_stack **stk, int index,	int (*r)(t_stack **),
			int (*rr)(t_stack **));

//=== Utils ===
void	ft_error(char *msg);
int		ft_min_pos(t_stack *stk_a);
void	print_stack(t_stack *stk, char *nome);

#endif