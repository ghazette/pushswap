/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_algo.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 11:05:31 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:11:50 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Trie B en rotate ou reverse pour que nb_min de B soit a la fin de la chaine.
*/

void	sort_b(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		i;

	i = 0;
	tmp = lst_b->head;
	while (tmp->next && i++)
	{
		if (tmp->nb == lst_b->nb_min)
			break ;
		else
			tmp = tmp->next;
	}
	if (i > lst_b->len / 2)
		while (lst_b->tail->nb != lst_b->nb_min)
			apply_reverse(lst_a, lst_b, "rrb", p);
	else
		while (lst_b->tail->nb != lst_b->nb_min)
			apply_rotate(lst_a, lst_b, "rb", p);
}

/*
** push les 2 premiers nombres dans la Liste B.
*/

void	start_algo(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int elem)
{
	if (H > (elem - 5))
		apply_rotate(lst_a, lst_b, "ra", p);
	else
		apply_push(lst_a, lst_b, "pb", p);
}

void	ft_maxtwo(t_list2 *lst)
{
	t_node *tmp;

	tmp = lst->head;
	while (tmp)
	{
		if (tmp->nb > lst->nb_max2 && tmp->nb != lst->nb_max)
			lst->nb_max2 = tmp->nb;
		tmp = tmp->next;
	}
}

void	ft_maximus(t_list2 *lst)
{
	t_node *tmp;

	tmp = lst->head;
	while (tmp)
	{
		if (tmp->nb > lst->nb_max)
			lst->nb_max = tmp->nb;
		tmp = tmp->next;
	}
}

void	ft_minus(t_list2 *lst_a, t_list2 *lst_b)
{
	if (lst_b->len == 0)
		lst_b->nb_min = lst_a->head->id;
	else if (lst_a->head->id < lst_b->nb_min)
		lst_b->nb_min = lst_a->head->id;
}
