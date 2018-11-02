/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 17:52:55 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 15:23:23 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_doublon(t_list2 *lst)
{
	t_node *curr;
	t_node *next;

	curr = lst->head;
	next = lst->head->next;
	while (curr && next)
	{
		while (next)
		{
			if (curr->nb == next->nb)
				return (KO);
			else
				next = next->next;
		}
		curr = curr->next;
		next = curr->next;
	}
	return (OK);
}

int		check_fmt(char *str)
{
	int		i;

	i = 0;
	if ((ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX))
		return (KO);
	while (str[i])
		if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1]) && !(isdigit(str[i - 1]))))
			i++;
		else
			return (KO);
	return (OK);
}

int		check_pile(int ac, char **av, t_list2 *lst)
{
	int i;
	int j;
	char **tab;

	if (ac == 1)
		j = 0;
	else
		j = 1;
	while (j < ac)
	{
		tab = ft_strsplit(av[j], ' ');
		i = 0;
		while (tab[i])
		{
			if (check_fmt(tab[i]) == KO)
				return (KO);
			add_element_end(lst, ft_atoi(tab[i]));
			i++;
		}
		ft_strdel(tab);
		j++;
	}
	return (check_doublon(lst));
}

int		check_order(t_list2 *lst)
{
	if (lst)
	{
		while (lst->head && lst->head->next)
		{
			if (lst->head->nb >= lst->head->next->nb)
				return (KO);
			else
				lst->head = lst->head->next;
		}
	}
	return (OK);
}

int		check_order_reverse(t_list2 *lst)
{
	if (lst)
	{
		while (lst->head && lst->head->next)
		{
			if (lst->head->nb <= lst->head->next->nb)
				return (KO);
			else
				lst->head = lst->head->next;
		}
	}
	return (OK);
}
