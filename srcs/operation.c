/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operation.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 15:53:05 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 15:14:55 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_rotate(t_list2 *lst)
{
    t_node *tmp;
    t_node *tmp2;

    if (lst != NULL && lst->head != NULL && lst->head->next)
    {
        tmp = lst->head;
        tmp2 = lst->tail;
        lst->head = tmp->next;
        lst->tail->next = tmp;
        lst->tail = lst->tail->next;
        lst->head->next = tmp->next->next;
        lst->tail->prev = tmp2;
        lst->head->prev = NULL;
        lst->tail->next = NULL;
    }
}

void    ft_swap_ps(t_list2 *lst)
{
    int tmp;

    if (lst->head && (lst)->head->next)
    {
        tmp = lst->head->nb;
        lst->head->nb = lst->head->next->nb;
        lst->head->next->nb = tmp;
    }
}

void    ft_push(t_list2 *lst_1, t_list2 *lst_2)
{
    if ((lst_2)->head != NULL)
    {
        add_element_head((lst_1), (lst_2)->head->nb);
        del_element_head(lst_2);
    }
}

void    ft_reverse(t_list2 *lst)
{
    t_node *tmp;
    t_node *tmp2;

    if (lst != NULL && lst->tail != NULL && lst->tail->prev)
    {
        tmp = lst->tail;
        tmp2 = lst->head;
        lst->tail = lst->tail->prev;
        lst->tail->prev = tmp->prev->prev;
        lst->head->prev = tmp;
        lst->head = lst->head->prev;
        lst->head->next = tmp2;
        lst->head->prev = NULL;
        lst->tail->next = NULL;
    }
}