/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 15:39:54 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:12:29 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_list(int v)
{
	t_node *mll;

	if (!(mll = malloc(sizeof(t_node))))
		return (NULL);
	if (mll)
	{
		mll->nb = v;
		mll->next = NULL;
		mll->prev = NULL;
	}
	return (mll);
}

void	del_element_end(t_list2 *lst)
{
	t_node *tmp;

	tmp = lst->tail;
	if (lst != NULL)
	{
		lst->tail = lst->tail->prev;
		lst->tail->next = NULL;
	}
	(lst)->len--;
	free(tmp);
}

void	del_element_head(t_list2 *lst)
{
	t_node *tmp;

	tmp = lst->head;
	if (tmp->next == NULL && tmp->prev == NULL)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else if (tmp->next == NULL)
	{
		lst->tail = tmp->prev;
		lst->tail->next = NULL;
	}
	else if (tmp->prev == NULL)
	{
		lst->head = tmp->next;
		lst->head->prev = NULL;
	}
	else
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
	}
	lst->len--;
	tmp = NULL;
	free(tmp);
}

void	add_element_end(t_list2 *lst, int v)
{
	t_node *new;

	new = create_list(v);
	if (lst->tail == NULL)
	{
		new->prev = NULL;
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		lst->tail->next = new;
		new->prev = lst->tail;
		lst->tail = new;
	}
	lst->len++;
}

// void	add_element_head(t_list2 *lst, int v)
// {
// 	t_node *new;

// 	new = create_list(v);
// 	if (lst->tail == NULL)
// 	{
// 		new->next = NULL;
// 		lst->head = new;
// 		lst->tail = new;
// 	}
// 	else
// 	{
// 		lst->head->prev = new;
// 		new->next = lst->head;
// 		lst->head = new;
// 	}
// 	lst->len++;
// }

void	add_element_head(t_list2 *lst, int v)
{
	t_node *new;

	new = create_list(v);
	if (lst->head == NULL)
	{
		new->next = NULL;
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		lst->head->prev = new;
		new->next = lst->head;
		lst->head = new;
	}
	lst->len++;
}

int		ft_lstlenght(t_node *p)
{
	int i;

	i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

void	view(t_list2 *lst)
{
	t_node *p;

	p = lst->head;
	while (p)
	{
		ft_printf("[%d](ID: %d)\n", p->nb, p->id);
		p = p->next;
	}
	ft_printf("\n");
}

void	new_list(t_list2 *lst)
{
	if (lst == malloc(sizeof(t_list2)))
	{
		lst->len = 0;
		lst->head = NULL;
		lst->tail = NULL;
	}
}