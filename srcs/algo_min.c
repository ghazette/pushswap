/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_min.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 15:48:57 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 09:47:35 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		num_min(t_list2 *lst)
{
	t_node *tmp;
	t_node *head;

	tmp = lst->head;
	head = lst->head;
	while (head)
	{
		if (tmp->nb > head->nb)
			tmp = head;
		head = head->next;
	}
	return (tmp->nb);
}

void	sort_bubble(t_list2 *lst_a, t_list2 *lst_b, int min, t_param *p)
{
	t_node *head;
	int i;
	int j;

	j = -1;
	i = 0;
	head = lst_a->head;
	while (head)
	{
		if (head->nb == min)
		{
			if (i <= lst_a->len / 2)
				while (++j < i)
					apply_rotate(lst_a, lst_b, "ra", p);
			else
			{
				j = lst_a->len;
				while (j > i)
				{
					apply_reverse(lst_a, lst_b, "rra", p);
					j--;
				}
			}
			apply_push(lst_a, lst_b, "pb", p);
			break;
		}
		head = head->next;
		i++;
	}
}

void	list_trois(t_node *tmp, t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	if (tmp->nb > tmp->next->nb && tmp->next->nb < tmp->next->next->nb && tmp->nb > tmp->next->next->nb)
		apply_rotate(lst_a, lst_b, "ra", p);
	else if (tmp->nb > tmp->next->nb && tmp->nb < tmp->next->next->nb)
		apply_swap(lst_a, lst_b, "sa", p);
	else if (tmp->nb > tmp->next->nb && tmp->nb > tmp->next->next->nb)
	{
		apply_rotate(lst_a, lst_b, "ra", p);
		apply_swap(lst_a, lst_b, "sa", p);				
	}
	else if (tmp->nb < tmp->next->nb && tmp->next->nb > tmp->next->next->nb && tmp->nb < tmp->next->next->nb)
	{
		apply_reverse(lst_a, lst_b, "rra", p);				
		apply_swap(lst_a, lst_b, "sa", p);								
	}			
	else if (tmp->nb < tmp->next->nb && tmp->next->nb > tmp->next->next->nb)
		apply_reverse(lst_a, lst_b, "rra", p);
}

void	algo_min(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	int min;
	t_node *tmp;

	tmp = lst_a->head;
	while (tmp && lst_a->head->next)
	{
		tmp = lst_a->head;	
		min = num_min(lst_a);
		if (lst_a->head->next == lst_a->tail)
		{
			if (lst_a->head->nb > lst_a->tail->nb)
				apply_swap(lst_a, lst_b, "sa", p);
		}
		else if (lst_a->len == 3)
		{
			list_trois(tmp, lst_a, lst_b, p);
			break;
		}
		else
			sort_bubble(lst_a, lst_b, min, p);
	}
	while (lst_b->len != 0)
		apply_push(lst_a, lst_b, "pa", p);
}