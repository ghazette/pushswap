/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_quicksort.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 11:11:33 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 11:29:27 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void    sort_a(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
// {
    // int tab[3];
    // int i;

    // i = -1;
    // tab[0] = lst_a->head->nb; 
    // tab[1] = lst_a->head->next->nb; 
    // tab[2] = lst_a->head->next->next->nb; 
//     if (tab[0] > tab[1] && tab[0] > tab[2])
//     {
//         apply_swap(lst_a, lst_b, "sa", p);
//         if (tab[1] > tab[2])
//         {
//             apply_rotate(lst_a, lst_b, "ra", p);
//             apply_swap(lst_a, lst_b, "sa", p);
//             apply_reverse(lst_a, lst_b, "rra", p);
//             apply_swap(lst_a, lst_b, "sa", p);
//         }
//         else
//         {
//             apply_rotate(lst_a, lst_b, "ra", p);
//             apply_swap(lst_a, lst_b, "sa", p);
//             apply_reverse(lst_a, lst_b, "rra", p);
//         }
//     }
//     if (tab[0] < tab[1] && tab[1] > tab[2])
//     {
//         if (tab[0] > tab[2])
//         {
//             apply_rotate(lst_a, lst_b, "ra", p);
//             apply_swap(lst_a, lst_b, "sa", p);
//             apply_reverse(lst_a, lst_b, "rra", p);
//             apply_swap(lst_a, lst_b, "sa", p);
//         }
//         else
//         {
//             apply_rotate(lst_a, lst_b, "ra", p);
//             apply_swap(lst_a, lst_b, "sa", p);
//             apply_reverse(lst_a, lst_b, "rra", p);
//         }
//     }
//     if (tab[0] < tab[2] && tab[1] < tab[2] && tab[0] > tab[1])
//         apply_swap(lst_a, lst_b, "sa", p);
// }

// void    sort_a(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
// {
//     int tab[5];
//     int i;

//     i = -1;
//     tab[0] = lst_a->head->nb; 
//     tab[1] = lst_a->head->next->nb; 
//     tab[2] = lst_a->head->next->next->nb;
//     tab[3] = lst_a->head->next->next->next->nb;
//     tab[4] = lst_a->head->next->next->next->next->nb;
//     while (++i < 4)
//     {
//         if (tab[i] < tab[i + 1])
//         {
//             apply_swap(lst_a, lst_b, "sa", p);
//             apply_push(lst_a, lst_b, "pb", p);
//         }
//         else
//             apply_push(lst_a, lst_b, "pb", p);
//         if (i > 0 && lst_b->head->nb < lst_b->head->next->nb)
//             apply_swap(lst_a, lst_b, "sb", p);
//     }
//     while (--i >= 0)
//     {
//         if (i > 0 && lst_b->head->nb < lst_b->head->next->nb)
//             apply_swap(lst_a, lst_b, "sb", p);
//         apply_push(lst_a, lst_b, "pa", p);
//         if (lst_a->head->nb > lst_a->head->next->nb)
//             apply_swap(lst_a, lst_b, "sa", p);
//     }
// }

// mettre i == 4;
int     choose_pivot(t_list2 *lst, int m)
{
    t_node *tmp;
    t_node *curr;
    int i;

    curr = lst->head;
    while (curr->next)
    {
        i = 0;
        tmp = lst->head;
        while (tmp->next)
        {
            if (curr->nb < tmp->nb)
                i++;
            tmp = tmp->next;
        }
        if (i == ((lst->len / 2) + m))
        {
            ft_printf("pvt: %d\n", curr->nb);
            return (curr->nb);
        }
        curr = curr->next;
    }
    return (0);
}

void    partition(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
    int pvt_a;
    int pvt_b;
    int pvt_ab;
    int pvt_bb;
    int m;

    m = 0;
    pvt_a = choose_pivot(lst_a, 0);
    pvt_b = 0;
    ft_quicksort(lst_a, lst_b, p, 0, pvt_a, pvt_b);
    while (check_order(lst_a) == KO && check_order_reverse(lst_b) == KO)
    {
        pvt_a = choose_pivot(lst_a, m);
        pvt_b = choose_pivot(lst_b, m);     
        pvt_ab = choose_pivot(lst_a, -m);
        pvt_bb = choose_pivot(lst_b, -m);
        ft_quicksort(lst_a, lst_b, p, 1, pvt_a, pvt_b);
        ft_quicksort(lst_a, lst_b, p, 1, pvt_ab, pvt_bb);
        m++;
    }
}

void    ft_quicksort(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int key, int pvt_a, int pvt_b)
{
    int len_a;
    int len_b;
    int pb;
    int pa;

    pb = 0;
    pa = 0;
    printf("pvtA: %d\n", pvt_a);
    len_a = lst_a->len;
    if (key == 0)
    {
        while (lst_a->head->next && len_a-- > 0)
        {
            if (lst_a->head->nb < pvt_a)
            {
                apply_push(lst_a, lst_b, "pb", p);
            }
            else
            {
                if (lst_b->len > 1)
                    lst_b->head->nb < lst_b->tail->nb ? apply_rotate(lst_a, lst_b, "rr", p) : apply_rotate(lst_a, lst_b, "ra", p);
                else
                    apply_rotate(lst_a, lst_b, "ra", p);
            }
        }
    }
    else if (key == 1)
    {
        while (lst_a->head->next && len_a-- > 0)
        {
            ft_printf("\033[32;01mList_A\033[00m\n");
            view(lst_a);
            ft_printf("\n\033[31;01mList_B\033[00m\n");
            view(lst_b);
            if (lst_a->head->nb > pvt_a)
                apply_rotate(lst_a, lst_b, "ra", p);
            else if (lst_a->head->nb < pvt_a)
            {
                apply_push(lst_a, lst_b, "pb", p);
                pa++;
                ft_printf("------------pa: %d\n", pa);
            }
        }
        while (pa-- >= 0)
        {
            apply_push(lst_a, lst_b, "pa", p);
            // pa--;
            // ft_printf("\033[32;01mList_A\033[00m\n");
            // view(lst_a);
            // ft_printf("\n\033[31;01mList_B\033[00m\n");
            // view(lst_b);
        }
        // ft_printf("\033[32;01mList_A\033[00m\n");
        // view(lst_a);
        // ft_printf("\n\033[31;01mList_B\033[00m\n");
        // view(lst_b);
        while (lst_b->head->next && len_b-- > 0)
        {
            if (lst_b->head->nb > pvt_b)
                apply_reverse(lst_a, lst_b, "rb", p);
            else if (lst_b->head->nb < pvt_b)
            {
                apply_push(lst_a, lst_b, "pa", p);   
                pb++;
            }
        }
         while (pb-- >= 0)
        {
            apply_push(lst_a, lst_b, "pb", p);
            // pb--;
        }
    }
        // ft_printf("\033[32;01mList_A\033[00m\n");
        // view(lst_a);
        // ft_printf("\n\033[31;01mList_B\033[00m\n");
        // view(lst_b);
}

// void    ft_quicksort(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int key)
// {
    // int pvt_a;
    // int pvt_b;
    // int len_a;
    // int len_b;
    // int limit;

//     pvt_a = 0;
//     pvt_b = 0;
//     if (lst_a->len > 5)
//         pvt_a = choose_pivot(lst_a);
//     if (lst_b->len > 5)
//         pvt_b = choose_pivot(lst_b);
//     // ft_printf("pvB: %d || pvA: %d\n", pvt_b, pvt_a);
//     len_a = lst_a->len;
//     len_b = lst_b->len;
//     if (key == 0)
        // while (lst_a->head->next && len_a-- > 0)
        // {
        //     if (lst_a->head->nb < pvt_a)
        //     {
        //         apply_push(lst_a, lst_b, "pb", p);
        //         // if (lst_b->len > 2)
        //         // {
        //         //     if (lst_b->head->nb < lst_b->head->next->nb)
        //         //         apply_swap(lst_a, lst_b, "sb", p);
        //         //     if (lst_b->head->nb < lst_b->tail->nb)
        //         //     {
        //         //         apply_reverse(lst_a, lst_b, "rrb", p);
        //         //         apply_swap(lst_a, lst_b, "sb", p);
        //         //         apply_rotate(lst_a, lst_b, "rb", p);
        //         //     }
        //         // }
        //     }
            // else
            // {
            //     if (lst_b->len > 1)
            //         lst_b->head->nb < lst_b->tail->nb ? apply_rotate(lst_a, lst_b, "rr", p) : apply_rotate(lst_a, lst_b, "ra", p);
            //     else
            //         apply_rotate(lst_a, lst_b, "ra", p);
            // }
//             // ft_printf("\033[32;01mList_A\033[00m\n");
//             // view(lst_a);
// 	        // ft_printf("\n\033[31;01mList_B\033[00m\n");
//             // view(lst_b);
//         }
//     else if (key == 1 && lst_b->len > 3)
//     {
//         limit = 0;
//         while (lst_b->head->next && len_b-- > 0 && limit < 5)
//         {
//             if (lst_b->head->nb > pvt_b)
//             {
//                 apply_push(lst_a, lst_b, "pa", p);
//                 limit++;
//             }
//             else
//                 apply_rotate(lst_a, lst_b, "rb", p);
//         }
//     }
//     else
//         while (lst_b->len != 0)
//             apply_push(lst_a, lst_b, "pa", p);
//     // ft_printf("\033[32;01mList_A\033[00m\n");
//     // view(lst_a);
//     // ft_printf("\n\033[31;01mList_B\033[00m\n");
//     // view(lst_b);
//     sort_a(lst_a, lst_b, p);
//     while (lst_b->len != 0)
//         ft_quicksort(lst_a, lst_b, p, 1);
//     // ft_quicksort(lst_a, lst_b, p, 1, limit + 3);
// }