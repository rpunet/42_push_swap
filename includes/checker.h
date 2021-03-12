/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:42:13 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 09:34:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/includes/libft.h"
# include <limits.h>

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
 */
# define BUFF_SIZE	64
# define OPERATIONS	11

typedef struct	s_buff
{
	int	val;
	struct s_buff *next;
}				t_buff;

/* enum				e_instr{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}; */

enum			e_instr{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

void	(*instructions[11])(t_list **a, t_list **b);

void	ft_wtf(t_list **a, t_list **b);
void	ft_insertion_sort_stack2(t_list **a, t_list **b);


void	ft_hugesort(t_list **a, t_list **b);

void	get_min_top(t_list **a);

void	ft_stacksort(t_list **a, t_list **b);



void	sb(t_list **a, t_list **b);
void	sa(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	ra(t_list **a, t_list **b);
void	rb(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, t_list **b);
void	rrb(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

int	signed_moves_to_top(t_list *a, int size, t_list *curr);
t_list	*ft_lst_find(t_list *a, int value, int *pos);


void	del(void *content);
void	ft_merge_sort(t_list **a, t_list **b, int size);



int		ft_atoi_error(const char *str);

void	ft_sort_set(t_list **a, t_list **b);
void	ft_bubble_sort(t_list **s);
void	ft_lstswap2(t_list **a, t_list **b);
void	ft_insertion_sort(t_list **a, t_list **b);
void	ft_simple3_sort(t_list **a, t_list **b);
int		*get_3values(int *ret, int *min, int *max, t_list *a);
void	ft_simple5_sort(t_list **a, t_list **b);
void	ft_simple5_insert_last(t_list **a, t_list **b);
void	ft_partition_sort(t_list **a, t_list **b, int size);
void	ft_partition_sort2(t_list **a, t_list **b, int size);



t_list	*ft_lst_max(t_list *a, int *pos);
t_list	*ft_lst_min(t_list *a, int *pos);
void	ft_clear_stack(t_list **a, t_list **b);
void	ft_lstswap(t_list **s);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstpop(t_list **top);


void	instr_buffer(int instr, t_list **a, t_list **b, int *i1, int *cont);
// void	ft_quick_sort(t_list **a, t_list **b, int n, int print, int *instr1, int *cont);
void	ft_quick_sort(t_list **a, t_list **b, int n, int print, t_buff **buffer);
int		ft_check_pivot(t_list *a, int pivot);

void	ft_quick_sort_stack2(t_list **a, t_list **b, int n, int print);

t_list * SortList1(t_list * pList);

void	print_stack(t_list *a);
void	ft_exit(char *str);
void	exec_command(t_list **a, t_list **b, int bonus_opt);



void	parse_argv(char *arg, t_list **a, int *bonus_opt);
void	check_dup(int n, t_list *a);

void	add_argv(int argc, char **argv, t_list **a);

int		ft_check_sort(t_list *a, t_list *b);



void	instr_to_buffer(int instr, t_buff **buffer);
t_buff	*ft_bufflast(t_buff *buffer);
void	ft_buffadd_back(t_buff **buffer, t_buff *new);
t_buff	*ft_buffnew(int inst);
void	ft_buffclear(t_buff **buffer);

void	print_short_buff(t_buff *buffer);
void	print_val(int instr);

#endif
