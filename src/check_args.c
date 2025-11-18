/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:15 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/18 16:05:13 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_list *lst)
{
	t_list	*lst1;
	t_list	*lst2;

	lst1 = lst;
	while (lst1)
	{
		lst2 = lst1->next;
		while (lst2)
		{
			if (lst1->content == lst2->content)
				return (1);
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
	return (0);
}

static void	convert_args(int ar, char *av[], t_list **lst)
{
	int		i;
	int		j;
	int		*nbr;
	char	**split;

	i = 1;
	while (i < ar)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			nbr = malloc(sizeof(int));
			*nbr = ft_atoi(split[j]);
			ft_lstadd_back(lst, ft_lstnew(nbr));
			j++;
		}
		free(split);
		i++;
	}
}

static int	check_args(int ar, char *av[])
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

int	check_nbr_args(int ar, char *av[], t_list **lst)
{
	convert_args(ar, av, lst);
	if (check_args(ar, av) && !check_doubles(*lst))
		return (1);
	ft_lstclear(lst, del);
	return (0);
}
