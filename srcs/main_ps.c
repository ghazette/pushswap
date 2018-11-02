/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_ps.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:16:38 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 16:06:22 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int ac, char **av)
{
	t_list2 lst_a;
	t_list2 lst_b;
	t_param *p;

	ft_bzero(&lst_a, sizeof(t_list2));
	ft_bzero(&lst_b, sizeof(t_list2));
	if ((p = init_param()) == 0)
		return (0);
	p->print = 1;
	if ((check_pile(ac, av, &lst_a)) == KO)
		return (write(2, "Error\n", 6));
	push_check(av, &lst_a, &lst_b, p);
	// ft_printf("\033[37;01m-------------FINISH------------\033[00m\n");
	// ft_printf("\033[32;01mList_A\033[00m\n");
	// view(&lst_a);
	// ft_printf("\n\033[31;01mList_B\033[00m\n");
	// view(&lst_b);
	return (0);
}
