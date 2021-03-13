/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:32:46 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 19:20:22 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sum(t_list *a, int depth)
{
	int		sum;

	sum = 0;
	while (a && depth--)
	{
		sum += *(int *)a->content;
		a = a->next;
	}
	return (sum);
}

int		half_to_b(t_list **a, t_list **b, int *toplen_n, t_buff **buffer)
{
	int	i;
	int	median;

	median = sum(*a, toplen_n[1]) / toplen_n[1];
	i = 0;
	while (i++ < toplen_n[1])
	{
		if (*(int *)(*a)->content <= median)
		{
			instr_to_buffer(PB, buffer, a, b);
			toplen_n[0] += 1;
		}
		else
			instr_to_buffer(RA, buffer, a, b);
	}
	return (i);
}

void	ft_quick_sort(t_list **a, t_list **b, int n, t_buff **buffer)
{
	int	toplen;
	int	i;
	int	toplen_n[2];

	if (n == 1 || ft_check_sort(*a, NULL))
		return ;
	toplen_n[1] = n;
	toplen_n[0] = 0;
	i = half_to_b(a, b, toplen_n, buffer);
	n = toplen_n[1];
	toplen = toplen_n[0];
	while (--i > toplen)
		instr_to_buffer(RRA, buffer, a, b);
	while (i--)
		instr_to_buffer(PA, buffer, a, b);
	ft_quick_sort(a, b, toplen, buffer);
	while (++i < toplen)
		instr_to_buffer(RA, buffer, a, b);
	ft_quick_sort(a, b, n - toplen, buffer);
	while (i--)
		instr_to_buffer(RRA, buffer, a, b);
}
