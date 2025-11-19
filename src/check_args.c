/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:15 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/19 14:18:40 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_stack *stack)
{
	t_stack	*stack1;
	t_stack	*stack2;

	stack1 = stack;
	while (stack1)
	{
		stack2 = stack1->next;
		while (stack2)
		{
			if (stack1->content == stack2->content)
				return (1);
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
	return (0);
}

static void	convert_args(int ar, char *av[], t_stack **stack)
{
	int		i;
	int		j;
	int		nbr;
	char	**split;

	i = 1;
	while (i < ar)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			nbr = ft_atoi(split[j]);
			ft_stack_add_back(stack, ft_stack_new(nbr));
			j++;
		}
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
		i++;
	}
}

static int	is_valid_args(int ar, char *av[])
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((!(ft_isdigit(av[j][i])) && !ft_issign(av[j][i])
			&& !ft_isspace(av[j][i])))
				return (0);
			i++;
		}
		if (!(ar == 2))
			j++;
		else
			break ;
	}
	return (1);
}

int	ft_check_args(int ar, char *av[], t_stack **stack)
{
	convert_args(ar, av, stack);
	if (is_valid_args(ar, av) && !check_doubles(*stack))
		return (1);
	return (0);
}
