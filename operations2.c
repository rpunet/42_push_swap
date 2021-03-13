/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:23:58 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:24:47 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
