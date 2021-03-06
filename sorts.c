/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:44:06 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/06 18:47:58 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sort_set(t_list **a, t_list **b)
{
	if (ft_check_sort(*a, NULL))
		return ;
	if (ft_lstsize(*a) == 3)
		ft_simple3_sort(a, b);
	// else if (ft_lstsize(*a) < 185)
	// 	ft_insertion_sort(a, b);
	else
		ft_quick_sort(a, b, ft_lstsize(*a));		// su puta madre despues de todo el lio, va fatal.
}

void	ft_insertion_sort(t_list **a, t_list **b)
{
	t_list	*min;
	int		pos = 0;
	int		size;

	size = ft_lstsize(*a);
	g_print = 1;
	while (*a)
	{
		min = ft_lst_min(*a, &pos);
		//ft_printf("%d <pos\n", pos);
		while (*a != min)
		{
			if (pos > (float)size / 2)
				rra(a, b);
			else
				ra(a, b);
		}
		if (ft_check_sort(*a, NULL))
			break;
		pb(a, b);
		size -= 1;
	}
	while (*b)
		pa(a, b);
}

int		*get_3values(int *ret, int *min, int *max, t_list *a)
{
	t_list	*tmp;

	tmp = ft_lst_min(a, NULL);
	*min = *(int *)tmp->content;
	tmp = ft_lst_max(a, NULL);
	*max = *(int *)tmp->content;
	ret[0] = *(int *)a->content;
	ret[1] = *(int *)a->next->content;
	ret[2] = *(int *)a->next->next->content;
	return (ret);
}

void	ft_simple3_sort(t_list **a, t_list **b)
{
	int	pos[3];
	int	min;
	int	max;
	g_print = 1;

	get_3values(pos, &min, &max, *a);
	if (pos[0] != max)
	{
		if (pos[1] == min)
			rra(a, b);
		else
			ra(a, b);
	}
	if ((pos[2] == min && pos[1] == max) || (pos[1] == min && pos[0] == max))
		rra(a, b);
	else
		sa(a, b);
	rra(a, b);
}


