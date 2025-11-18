/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:15 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/18 13:58:12 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
			if (ft_atoi(lst1->content) == ft_atoi(lst2->content))
				return (1);
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
	return (0);
}

static void	convert_args(int ar, char *av[], t_list **lst, int is_single)
{
	int		i;
	char	**split;

	i = 0;
	if (is_single)
	{
		split = ft_split(av[1], ' ');
		while (split[i])
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(split[i++])));
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
	}
	else
		while (i < ar - 1)
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(av[(i++) + 1])));
}

static int	check_args(char *av[], int is_single)
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
		if (!is_single)
			j++;
		else
			break ;
	}
	return (1);
}

int	check_nbr_args(int ar, char *av[])
{
	t_list	*lst;

	lst = NULL;
	if (ar == 2)
	{
		convert_args(ar, av, &lst, 1);
		if (check_args(av, 1) && !check_doubles(lst))
			return (1);
	}
	else if (ar > 2)
	{
		convert_args(ar, av, &lst, 0);
		if (check_args(av, 0) && !check_doubles(lst))
			return (1);
	}
	ft_lstclear(&lst, del);
	return (0);
}
