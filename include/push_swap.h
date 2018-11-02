/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 16:54:55 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:01:45 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include <limits.h>
# include <unistd.h>
# include <math.h>
# define KO 0
# define OK 1
# define RT 0
# define RV 1
# define BF 0
# define AF 1
# define H lst_a->head->id
# define HN lst_a->head->next->id
# define HNN lst_a->head->next->next->id
# define T lst_a->tail->id

typedef struct		s_node
{
	int				nb;
	int				id;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_list2
{
	t_node			*head;
	t_node			*tail;
	int				len;
	int				nb_max;
	int				nb_max2;
	int				nb_min;
}					t_list2;

typedef struct		s_param
{
	int				shot;
	int				rot;
	int				print;
	int				tab[4];
	int				res[4];
	int				cnt;
	int				loop;
}					t_param;

/*
** main
*/
int					main(int ac, char **av);
int					main(int ac, char **av);
t_param				*init_param();

/*
** Tool
*/
void				add_element_end(t_list2 *lst, int v);
void				add_element_head(t_list2 *lst, int v);
void				view(t_list2 *p);
t_node				*create_list(int v);
int					ft_lstlenght(t_node *p);
void				del_element_end(t_list2 *lst);
void				del_element_head(t_list2 *lst);
void				new_list(t_list2 *lst);

/*
** Check
*/
int					check_doublon(t_list2 *lst);
int					check_fmt(char *s);
int					check_order(t_list2 *lst);
int					check_ope(char *s);
int					check_pile(int ac, char **av, t_list2 *lst);
int					check_order_reverse(t_list2 *lst);

/*
** Operation
*/
void				ft_rotate(t_list2 *lst);
void				ft_swap_ps(t_list2 *lst);
void				ft_reverse(t_list2 *lst);
void				ft_push(t_list2 *lst_1, t_list2 *lst_2);

/*
** Apply
*/
void				apply_ope(t_list2 *la, t_list2 *lb, char *s, t_param *p);
void				apply_push(t_list2 *la, t_list2 *lb, char *s, t_param *p);
void				apply_swap(t_list2 *la, t_list2 *lb, char *s, t_param *p);
void				apply_rotate(t_list2 *la, t_list2 *lb, char *s, t_param *p);
void				apply_reverse(t_list2 *la, t_list2 *lb, char *s,
					t_param *p);

/*
** algo_min
*/
int					num_min(t_list2 *lst);
void				sort_bubble(t_list2 *la, t_list2 *lb, int min, t_param *p);
void				algo_min(t_list2 *la, t_list2 *lb, t_param *p);
void				list_trois(t_node *tmp, t_list2 *la, t_list2 *lb,
					t_param *p);

/*
** algo_max
*/
void				algo_max(t_list2 *la, t_list2 *lb, t_param *p);
void				opti_afpush(t_list2 *la, t_list2 *lb, t_param *p);
int					number_hits(t_list2 *la, t_list2 *lb, t_param *p, int nb);
int					number_chse(t_list2 *la, t_list2 *lb, t_param *p);
void				sort_number(t_list2 *la, t_list2 *lb, t_param *p, int nb);

/*
** tools_algo
*/
void				start_algo(t_list2 *la, t_list2 *lb, t_param *p, int elem);
void				sort_b(t_list2 *la, t_list2 *lb, t_param *p);
void				ft_minus(t_list2 *la, t_list2 *lb);
void				ft_maximus(t_list2 *lst);
void				ft_maxtwo(t_list2 *lst);

/*
** push_check
*/
int					push_check(char **av, t_list2 *la, t_list2 *lb, t_param *p);
int					check_swap(t_list2 *la, t_list2 *lb, t_param *p);

/*
** init
*/
t_param				*init_param();

/*
** real_quick
*/
int					sort_quick(t_list2 *lst_a);
int					*list_to_tab(t_list2 *lst);
void				quicksort(int *tab, int min, int max);
int					ft_len(int *tab);


void	id_list(t_list2 *lst, int *tab, int max);


#endif
