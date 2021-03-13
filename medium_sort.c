/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:18:16 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:01:07 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion_part_sort(t_list **a, t_list **b)
{
	t_list	*min;
	int		s;
	int		s2;
	int		a_len;
	int		pos;

	s = ft_lstsize(*a);
	s2 = s / 2;
	while (s2 > 0)
	{
		pb(a, b, 1);
		s2--;
	}
	ft_insertion_sort(a, b);
	ft_insertion_sort_stack2(a, b);
	a_len = ft_lstsize(*a);
	merge_stacks(a, b, a_len);
	min = ft_lst_min(*a, &pos);
	while (*a != min)
	{
		if (pos > (float)s / 2)
			rra(a, b, 1);
		else
			ra(a, b, 1);
	}
}

void	merge_stacks(t_list **a, t_list **b, int len)
{
	while (*b && len)
	{
		if (*(int*)(*a)->content > *(int*)(*b)->content)
		{
			len++;
			pa(a, b, 1);
		}
		else
		{
			ra(a, b, 1);
			len--;
		}
	}
	while (*b)
	{
		pa(a, b, 1);
		ra(a, b, 1);
	}
}

void	ft_insertion_sort_stack2(t_list **a, t_list **b)
{
	t_list	*min;
	int		pos;
	int		size;
	int		cont;

	cont = 0;
	size = ft_lstsize(*b);
	while (*b)
	{
		min = ft_lst_min(*b, &pos);
		while (*b != min)
		{
			if (pos > (float)size / 2)
				rrb(a, b, 1);
			else
				rb(a, b, 1);
		}
		if (ft_check_sort(*b, NULL))
			break ;
		pa(a, b, 1);
		size -= 1;
		cont++;
	}
	while (cont--)
		pb(a, b, 1);
}
