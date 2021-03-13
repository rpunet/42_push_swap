/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:32:44 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:27:20 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		ft_putstr_fd("ra\n", 1);
	while (b)
		break ;
	if (!a || !*a)
		return ;
	if (!(*a)->next)
		return ;
	tmp = ft_lstpop(a);
	ft_lstadd_back(a, tmp);
}

void	rb(t_list **a, t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		ft_putstr_fd("rb\n", 1);
	while (a)
		break ;
	if (!b || !*b)
		return ;
	if (!(*b)->next)
		return ;
	tmp = ft_lstpop(b);
	ft_lstadd_back(b, tmp);
}

void	rra(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		ft_putstr_fd("rra\n", 1);
	while (b)
		break ;
	if (!a || !*a)
		return ;
	if (!(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	ft_lstadd_front(a, last);
	tmp->next = NULL;
}

void	rrb(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		ft_putstr_fd("rrb\n", 1);
	while (a)
		break ;
	if (!b || !*b)
		return ;
	if (!(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	ft_lstadd_front(b, last);
	tmp->next = NULL;
}
