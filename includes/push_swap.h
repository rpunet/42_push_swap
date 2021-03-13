/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:42:13 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 23:21:28 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "structs.h"
# include <limits.h>

# define BUFF_SIZE	64
# define OPERATIONS	11

void	sb(t_list **a, t_list **b, int print);
void	sa(t_list **a, t_list **b, int print);
void	ss(t_list **a, t_list **b, int print);
void	pa(t_list **a, t_list **b, int print);
void	pb(t_list **a, t_list **b, int print);
void	ra(t_list **a, t_list **b, int print);
void	rb(t_list **a, t_list **b, int print);
void	rr(t_list **a, t_list **b, int print);
void	rra(t_list **a, t_list **b, int print);
void	rrb(t_list **a, t_list **b, int print);
void	rrr(t_list **a, t_list **b, int print);

t_list	*ft_lst_min(t_list *a, int *pos);
t_list	*ft_lst_max(t_list *a, int *pos);
void	ft_clear_stack(t_list **a, t_list **b);
void	ft_lstswap(t_list **s);
t_list	*ft_lstpop(t_list **top);

int		ft_atoi_error(const char *str);
void	print_stack(t_list *a);
void	ft_exit(char *str);
void	del(void *content);
int		ft_check_sort(t_list *a, t_list *b);

void	parse_argv(char *arg, t_list **a, int *bonus_opt);
void	add_argv(int argc, char **argv, t_list **a);
void	check_dup(int n, t_list *a);

void	ft_sort_set(t_list **a, t_list **b);

int		*get_3values(int *ret, int *min, int *max, t_list *a);
void	ft_simple3_sort(t_list **a, t_list **b);

void	ft_insertion_part_sort(t_list **a, t_list **b);
void	ft_insertion_sort(t_list **a, t_list **b);
void	ft_insertion_sort_stack2(t_list **a, t_list **b);
void	merge_stacks(t_list **a, t_list **b, int len);

void	ft_quick_sort(t_list **a, t_list **b, int n, t_buff **buffer);
int		sum(t_list *a, int depth);
int		half_to_b(t_list **a, t_list **b, int *toplen_n, t_buff **buffer);
void	print_short_buff(t_buff *buffer, int cont, int instr);
void	print_val(int instr);
void	instr_to_buffer(int instr, t_buff **buffer, t_list **a, t_list **b);

t_buff	*ft_bufflast(t_buff *buffer);
void	ft_buffadd_back(t_buff **buffer, t_buff *new);
t_buff	*ft_buffnew(int inst);
void	ft_buffclear(t_buff **buffer);
void	(*g_instructions[11])(t_list **a, t_list **b, int print);

void	exec_command(t_list **a, t_list **b, int bonus_opt);
void	check_instr(int inum, char *line, t_list **a, t_list **b);

#endif
