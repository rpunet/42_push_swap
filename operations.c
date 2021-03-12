/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:32:44 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 12:08:15 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_list **a, t_list **b, int print)
{
	if (print)
		ft_putstr_fd("sb\n", 1);
	if (a && b)
		ft_lstswap(b);
}

void	sa(t_list **a, t_list **b, int print)
{
	if (print)
		ft_putstr_fd("sa\n", 1);
	if (a && b)
		ft_lstswap(a);
}

void	ss(t_list **a, t_list **b, int print)
{
	if (print)
		ft_putstr_fd("ss\n", 1);
	ft_lstswap(a);
	ft_lstswap(b);
}

void	pa(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	if (print)
		ft_putstr_fd("pa\n", 1);
	if (*b)
	{
		tmp = ft_lstpop(b);
		ft_lstadd_front(a, tmp);
	}
}

void	pb(t_list **a, t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		ft_putstr_fd("pb\n", 1);
	if (*a)
	{
		tmp = ft_lstpop(a);
		ft_lstadd_front(b, tmp);
	}
}

void	ra(t_list **a, t_list **b, int print)
{

	t_list	*tmp;

	if (print)
		ft_putstr_fd("ra\n", 1);
	while (b)			// para que no proteste la b no usada
		break;
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
	while (a)			// para que no proteste la a no usada
		break;
	if (!b || !*b)
		return ;
	if (!(*b)->next)
		return ;
	tmp = ft_lstpop(b);
	ft_lstadd_back(b, tmp);
}

void	rr(t_list **a, t_list **b, int print)
{
	ra(a, b, print);
	rb(a, b, print);
}

void	rra(t_list **a, t_list **b, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		ft_putstr_fd("rra\n", 1);
	while (b)
		break;
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
		break;
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

void	rrr(t_list **a, t_list **b, int print)
{
	rra(a, b, print);				// solucionar print de es
	rrb(a, b, print);
}
