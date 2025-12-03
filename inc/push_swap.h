/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 17:18:31 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

//Stack


typedef struct s_stack
{
	int				index;
	int				lis_length;
	int				is_lis;
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stack_new(int content);
void	ft_stack_add_front(t_stack **stk, t_stack *new_stk);
void	ft_stack_add_back(t_stack **stk, t_stack *new_stk);
void	ft_stack_clear(t_stack **stk);
int		ft_stack_size(t_stack *stk);

//Check args
int		check_args(int ar, char *av[], t_stack **stk);

//Instructions
int		swap(t_stack **stk_swap);
int		sa(t_stack **stk_a);
int		sb(t_stack **stk_b);
int		ss(t_stack **stk_a, t_stack **stk_b);

int		push(t_stack **stk_a, t_stack **stk_b);
int		pa(t_stack **stk_a, t_stack **stk_b);
int		pb(t_stack **stk_a, t_stack **stk_b);

int		ra(t_stack **stk_a);
int		rb(t_stack **stk_b);
int		rr(t_stack **stk_a, t_stack **stk_b);

int		rra(t_stack **stk_a);
int		rrb(t_stack **stk_b);
int		rrr(t_stack **stk_a, t_stack **stk_b);

//Algorithm
int		sort_2(t_stack **stk_a);
int		sort_3(t_stack **stk_a, t_stack **stk_b);
int		sort_4(t_stack **stk_a, t_stack **stk_b);
int		sort_5(t_stack **stk_a, t_stack **stk_b);
void	radix_sort(t_stack **stk_a, t_stack **stk_b, int stk_size, int *ops);
int		lis(t_stack **stk_a);
void	set_is_lis(t_stack **stk_a, int max_len);
void	move_lis(t_stack **stk_a, t_stack **stk_b, int stk_size, int *ops);

//Utils
void	ft_error(char *msg);
int		ft_min_index(t_stack *stk_a);
int		ft_max_index(t_stack *stk_a);
void	add_index(t_stack **stk_a);
void	print_stack(t_stack *stk, char *nome);

#endif