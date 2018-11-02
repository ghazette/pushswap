/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_check.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:36:50 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 10:37:34 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int    push_check(char **av, t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
    if (p->print == 0)
    {
        while (get_next_line(0, &av[0]))
		{
			if (check_ope(av[0]) == 0)
				return (write(2, "Error\n", 6));
			else
				apply_ope(lst_a, lst_b, av[0], p);
        }
    }
    else
    {
		if (check_swap(lst_a, lst_b, p) == OK)
			return (0);
        if (lst_a->len < 10)
            algo_min(lst_a, lst_b, p);
        else
		    algo_max(lst_a, lst_b, p);
    }
    return (0);
}

int		check_swap(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	t_node *tmp;
	int app;

	tmp = lst_a->head;
	app = 0;

	if (lst_a->len > 1)
	{
		if (lst_a->head->nb > lst_a->head->next->nb)
		{
			tmp = tmp->next;
			app = 1;
		}
		else if (lst_a->tail->prev->nb > lst_a->tail->nb)
			app = 2;
		while (tmp && tmp->next)
		{
			if (app == 1 && tmp->nb >= tmp->next->nb)
				return (KO);
			else if (app == 2 && tmp->nb != lst_a->tail->prev->nb && tmp->nb > tmp->next->nb)
				return (KO);
			else if (tmp->nb > tmp->next->nb && app != 2)
				return (KO);
			else
				tmp = tmp->next;
		}
		if (app == 1)
			apply_swap(lst_a, lst_b, "sa", p);
		else if (app == 2)
		{
			apply_reverse(lst_a, lst_b, "rra", p);
			apply_reverse(lst_a, lst_b, "rra", p);
			apply_swap(lst_a, lst_b, "sa", p);
			apply_rotate(lst_a, lst_b, "ra", p);
			apply_rotate(lst_a, lst_b, "ra", p);
		}
	}
	return (OK);
}


int		check_ope(char *str)
{
	if ((ft_strcmp(str, "sa") == 0)
	|| (ft_strcmp(str, "sb") == 0)
	|| (ft_strcmp(str, "ss") == 0)
	|| (ft_strcmp(str, "pa") == 0)
	|| (ft_strcmp(str, "pb") == 0)
	|| (ft_strcmp(str, "rra") == 0)
	|| (ft_strcmp(str, "rrb") == 0)
	|| (ft_strcmp(str, "rrr") == 0)
	|| (ft_strcmp(str, "ra") == 0)
	|| (ft_strcmp(str, "rb") == 0)
	|| (ft_strcmp(str, "rr") == 0))
		return (1); 
	else
		return (0);
}