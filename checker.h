/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:42:13 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/06 18:20:21 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libftPLUS/includes/libft.h"
# include <limits.h>

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
 */
# define BUFF_SIZE	64
# define OPERATIONS	11
int	g_print;

/*
enum				e_instr{
	sa,
	sb,
	ss,
	pa,
	pb,
}; */

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




void	del(void *content);



int		ft_atoi_error(const char *str);

void	ft_sort_set(t_list **a, t_list **b);
void	ft_bubble_sort(t_list *s, int size);
void	ft_insertion_sort(t_list **a, t_list **b);
void	ft_simple3_sort(t_list **a, t_list **b);
int		*get_3values(int *ret, int *min, int *max, t_list *a);



t_list	*ft_lst_max(t_list *a, int *pos);
t_list	*ft_lst_min(t_list *a, int *pos);
void	ft_clear_stack(t_list **a, t_list **b);
void	ft_lstswap(t_list **s);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstpop(t_list **top);



void	ft_quick_sort(t_list **a, t_list **b, int n);
int		ft_check_pivot(t_list *a, int pivot);

t_list * SortList1(t_list * pList);

void	print_stack(t_list *a);
void	ft_exit(char *str);
void	exec_command(t_list **a, t_list **b);


void	parse_argv(char *arg, t_list **a);
void	check_dup(int n, t_list *a);

void	add_argv(int argc, char **argv, t_list **a);

int		ft_check_sort(t_list *a, t_list *b);

#endif
