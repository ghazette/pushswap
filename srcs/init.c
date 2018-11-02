/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 13:26:52 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 12:56:08 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_param	*init_param()
{
	t_param *p;

	p = malloc(sizeof(t_param));
	if (p)
	{
		p->shot = 0;
		p->rot = 0;
		p->cnt = 0;
		p->loop = 0;
		p->print = 0;
		return (p);
	}
	return (0);
}