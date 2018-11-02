/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   real_quick.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 09:45:24 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 14:46:13 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     sort_quick(t_list2 *lst_a)
{
    int *tab;
    int max;
    int min;

    min = 0;
    tab = list_to_tab(lst_a);
    max = lst_a->len;
    quicksort(tab, min, max - 1);
    int i = 0;
    while (i < max)
        i++;
    id_list(lst_a, tab, max);
    return (max);
}

void	id_list(t_list2 *lst, int *tab, int max)
{
	int i;
	t_node *tmp;

	i = -1;
	while (++i < max)
	{
		tmp = lst->head;
		while (tmp)
		{
			if (tmp->nb == tab[i])
			{
				tmp->id = i;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

int     *list_to_tab(t_list2 *lst)
{
    int *tab;
    int i;
    t_node *tmp;

    tmp = lst->head;
    i = 0;
    if (!(tab = malloc(sizeof(int) * (lst->len + 1))))
        return (0);
    while (tmp)
    {
        tab[i] = tmp->nb;
        i++;
        tmp = tmp->next;
    }
    return (tab);
}

void    quicksort(int *tab, int min, int max)
{
    int i;
    int j;
    int pivot;

    if (min < max)
    {
        pivot = min;
        i = min;
        j = max;

        while (i < j)
        {
            while (tab[i] <= tab[pivot]&&i<max)
                i++;
            while (tab[j] > tab[pivot])
                j--;
            if (i < j)
                ft_swap(&(tab[i]), &(tab[j]));
        }
    ft_swap(&(tab[j]), &(tab[pivot]));
    quicksort(tab, min, j - 1);
    quicksort(tab, j + 1, max);
    }
}