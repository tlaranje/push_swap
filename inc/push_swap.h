/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/19 16:46:46 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

//Stack
typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stack_new(int content);
void	ft_stack_add_front(t_stack **stack, t_stack *new);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	ft_stack_clear(t_stack **stack);
int		ft_stack_size(t_stack *stack);

//Check args
int		ft_check_args(int ar, char *av[], t_stack **stack);

//Instructions
int		swap(t_stack **stack_swap);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

int		push(t_stack **stack_1, t_stack **stack_2);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

void	reverse_push(t_stack **stack_1, t_stack **stack_2);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

//Algorithm
int	ft_sort(t_stack **stack);

//Utils
void	ft_error(char *msg);

#endif