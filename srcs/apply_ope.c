/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_ope.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 16:08:35 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 14:46:43 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    apply_ope(t_list2 *la, t_list2 *lb, char *s, t_param *p)
{
    if (s[0] == 'p')
        apply_push(la, lb, s, p);
    if (s[0] == 's')
        apply_swap(la, lb, s, p);
    if (ft_strcmp(s, "rr") == 0 || ft_strcmp(s, "rb") == 0 || ft_strcmp(s, "ra") == 0)
        apply_rotate(la, lb, s, p);
    if (ft_strcmp(s, "rrr") == 0 || ft_strcmp(s, "rrb") == 0 || ft_strcmp(s, "rra") == 0)
        apply_reverse(la, lb, s, p);
}

void    apply_push(t_list2 *lst_a, t_list2 *lst_b, char *str, t_param *p)
{
    int i;

    i = 0;
    if (p->print == 1)
        i = 1;
    if (ft_strcmp(str, "pa") == 0)
        ft_push(lst_a, lst_b);
    if (ft_strcmp(str, "pb") == 0)
        ft_push(lst_b, lst_a);
    if (i == 1)
        p->print = 1;
    if (p->print == 1)
        ft_printf("%s\n", str);
}
void    apply_swap(t_list2 *lst_a, t_list2 *lst_b, char *str, t_param *p)
{
    if (ft_strcmp(str, "sa") == 0)
        ft_swap_ps(lst_a);
    if (ft_strcmp(str, "sb") == 0)
        ft_swap_ps(lst_b);
    if (ft_strcmp(str, "ss") == 0)
    {
        ft_swap_ps(lst_a);
        ft_swap_ps(lst_b);
    }
    if (p->print == 1)
        ft_printf("%s\n", str);
}
void    apply_rotate(t_list2 *lst_a, t_list2 *lst_b, char *str, t_param *p)
{
    if (ft_strcmp(str, "ra") == 0)
        ft_rotate(lst_a);
    if (ft_strcmp(str, "rb") == 0)
        ft_rotate(lst_b);
    if (ft_strcmp(str, "rr") == 0)
    {
        ft_rotate(lst_a);
        ft_rotate(lst_b);
    }
    if (p->print == 1)
        ft_printf("%s\n", str);
}
void    apply_reverse(t_list2 *lst_a, t_list2 *lst_b, char *str, t_param *p)
{
    if (ft_strcmp(str, "rra") == 0)
        ft_reverse(lst_a);
    if (ft_strcmp(str, "rrb") == 0)
        ft_reverse(lst_b);
    if (ft_strcmp(str, "rrr") == 0)
    {
        ft_reverse(lst_a);
        ft_reverse(lst_b);
    }
    if (p->print == 1)
        ft_printf("%s\n", str);
}
