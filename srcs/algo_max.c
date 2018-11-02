/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_max.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:32:06 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:15:23 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
checker tous les chiffres compter le nobre de coups en prenant en compte les doubles actions (rr && rrr && ss) /!\
*/
/*
** COMPTER LE NOMBRE DE COUPS SI L'ON NE SELECTIONNE PAS LST_A->HEAD
** p->rot = 1 : reverse;
** p->rot = 0 : rotate;
** p->loop = 0 : BF;
** p->loop = 1 : AF;
** p->res[0] : nombre de coups
** p->res[1] : nombre
** p->res[2] : rotate ou reverse
** p->res[3] : appliquer avant ou apres le push
*/

void	algo_max(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	int elem;
	int	nb;

	nb = 0;
	elem = sort_quick(lst_a);
	lst_a->nb_max = elem;
	while (lst_a->len > 5)
	{
		if (lst_b->len < 2)
			start_algo(lst_a, lst_b, p, elem);
		else
		{
			nb = number_chse(lst_a, lst_b, p);
			sort_number(lst_a, lst_b, p, nb);
		}
	}
	printf("lstA\n");
	view(lst_a);
	printf("lstB\n");
	view(lst_b);
}

/*
** Compte le nombre de coups pour chaque nombre.
*/

int		number_hits(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int nb)
{
	int		cnt;
	t_node	*tmp;

	tmp = lst_b->head;
	p->rot = 0;
	p->loop = 0;
	cnt = 0;
	if (lst_b->nb_min != lst_b->tail->id && nb > lst_b->head->id
	&& nb < lst_b->tail->id)
		cnt = 0;
	else if (lst_b->len == 2 && lst_b->nb_min == lst_b->tail->id
	&& nb < lst_b->head->id && nb > lst_b->tail->id)
		cnt = 1;
	else if (lst_b->nb_min != lst_b->tail->id && nb < lst_b->nb_min)
	{
		while (tmp->id != lst_b->nb_min && ++cnt && tmp->next)
			tmp = tmp->next;
		cnt++;
		p->rot = 0;
	}
	else if (lst_b->nb_min != lst_b->tail->id && nb < lst_b->head->id)
	{
		while (nb < tmp->id && ++cnt)
			tmp = tmp->next;
	}
	else if (lst_b->nb_min != lst_b->tail->id && nb > lst_b->head->id)
	{
		while (tmp->id != lst_b->nb_min && ++cnt)
			tmp = tmp->next;
		tmp = tmp->next;
		cnt++;
		while (nb < tmp->id && ++cnt)
			tmp = tmp->next;
	}
	else if (lst_b->nb_min == lst_b->tail->id && nb < lst_b->nb_min)
		cnt = 0;
	else if (lst_b->nb_min == lst_b->tail->id && nb > lst_b->head->id)
		cnt = 0;
	else if (lst_b->nb_min == lst_b->tail->id)
	{
		while (nb < tmp->id && ++cnt)
			tmp = tmp->next;
	}
	return (cnt);
}

// /*
// ** Retourne le nombre avec le moins de coups pour etre trier.
// */

int		number_chse(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	int cnt;
	int i;
	int enter;

	i = -1;
	enter = 0;
	if (lst_a->head)
		p->tab[0] = H;
	if (lst_a->head->next && lst_a->len > 1)
		p->tab[1] = HN;
	if (lst_a->head->next->next && lst_a->len > 2)
		p->tab[2] = HNN;
	if (lst_a->tail && lst_a->len > 1)
		p->tab[3] = T;
	while (++i < 4)
	{
		cnt = 0;
		if (i == 1 || i == 3)
			cnt = 1;
		if (i == 2)
			cnt = 2;
		cnt += number_hits(lst_a, lst_b, p, p->tab[i]);
		printf("tab[%d]: %d || id max: %d\n", i, p->tab[i], lst_a->nb_max - 5);
		if ((enter == 0 || cnt < p->res[0]) && (p->tab[i]
		< lst_a->nb_max - 5))
		{
			enter = 1;
			p->res[0] = cnt;
			p->res[1] = p->tab[i];
			p->res[2] = p->rot;
			p->res[3] = p->loop;
		}
	}
	printf("return: %d\n", p->res[1]);
	return (p->res[1]);
}

// /*
// ** Appliquer le tri pour le nombre choisi.
// */

void	sort_number(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int nb)
{
	if (nb == HN && p->res[0]--)
		apply_swap(lst_a, lst_b, "sa", p);
	else if (nb == HNN && lst_a->len > 2)
	{
		p->res[0] -= 2;
		apply_rotate(lst_a, lst_b, "ra", p);
		apply_swap(lst_a, lst_b, "sa", p);
	}
	else if (nb == T && p->res[0]--)
		apply_reverse(lst_a, lst_b, "rra", p);
	if (p->res[3] == BF)
		while (p->res[0] > 0 && p->res[0]--)
			p->res[2] == 0 ? apply_rotate(lst_a, lst_b, "rb", p)
			: apply_reverse(lst_a, lst_b, "rrb", p);
	ft_minus(lst_a, lst_b);
	apply_push(lst_a, lst_b, "pb", p);
	if (p->res[3] == AF)
		opti_afpush(lst_a, lst_b, p);
}

void	opti_afpush(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	t_list2 *tmp;
	t_node *la;
	int hit;
	int cnt;

	cnt = 0;
	hit = p->res[0];
	tmp = lst_b;
	la = lst_a->head;
	while (hit > 0 && hit--)
		p->res[2] == 0 ? ft_rotate(tmp) : ft_reverse(tmp);
	view(tmp);
	hit = p->res[0];
	while (hit-- && la->next)
	{
		if (number_hits(lst_a, lst_b, p, la->nb) > (number_hits(lst_a, lst_b, p, la->next->nb) + cnt))
		{
			cnt++;
			la = la->next;
		}
		else
			break;
	}
	while (p->res[0] > 0 && p->res[0]--)	
		if (p->res[2] == 0)
			cnt == 0 ? apply_rotate(lst_a, lst_b, "rb", p) : apply_rotate(lst_a, lst_b, "rr", p);
		else if (p->res[2] == 1)
			cnt == 0 ? apply_rotate(lst_a, lst_b, "rrb", p) : apply_rotate(lst_a, lst_b, "rrr", p);
}

// void	algo_max(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
// {
// 	int nb;

// 	nb = 0;
// 	ft_maximus(lst_a);
// 	ft_maxtwo(lst_a);
	// while (lst_a->len > 2)
	// {
	// 	if (lst_b->len < 2)
	// 		start_algo(lst_a, lst_b, p);
	// 	else
	// 	{
	// 		nb = number_chse(lst_a, lst_b, p);
	// 		sort_number(lst_a, lst_b, p, nb);
	// 	}
	// }
// 	if (lst_a->head->nb > lst_a->tail->nb)
// 		apply_swap(lst_a, lst_b, "sa", p);
// 	sort_b(lst_a, lst_b, p);
// 	if (lst_b->len > 0)
// 		while (lst_b->len > 0)
// 			apply_push(lst_a, lst_b, "pa", p);
// }
