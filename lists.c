/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:06:23 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 19:23:50 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_min(t_list *a, int *pos)
{
	int		i;
	t_list	*tmp;

	i = __INT_MAX__;
	tmp = a;
	while (a)
	{
		if (*(int *)(a->content) < i)
			i = *(int *)(a->content);
		a = a->next;
	}
	a = tmp;
	if (pos != NULL)
		*pos = 0;
	while ((*(int *)(a->content) != i))
	{
		if (pos != NULL)
			(*pos) = *pos + 1;
		a = a->next;
	}
	return (a);
}

t_list	*ft_lst_max(t_list *a, int *pos)
{
	int		i;
	t_list	*tmp;

	i = INT_MIN;
	tmp = a;
	while (a)
	{
		if (*(int *)(a->content) > i)
			i = *(int *)(a->content);
		a = a->next;
	}
	a = tmp;
	if (pos != NULL)
		*pos = 0;
	while ((*(int *)(a->content) != i))
	{
		if (pos != NULL)
			(*pos) = *pos + 1;
		a = a->next;
	}
	return (a);
}

void	ft_clear_stack(t_list **a, t_list **b)
{
	void	(*del_ptr)(void*);

	del_ptr = del;
	ft_lstclear(a, (*del_ptr));
	ft_lstclear(b, (*del_ptr));
}

void	ft_lstswap(t_list **s)
{
	t_list	*tmp;

	if (*s && (*s)->next)
	{
		tmp = (*s)->next;
		(*s)->next = tmp->next;
		tmp->next = *s;
		*s = tmp;
	}
}

t_list	*ft_lstpop(t_list **top)
{
	t_list	*tmp;

	if (*top == NULL)
		return (NULL);
	tmp = *top;
	*top = (*top)->next;
	tmp->next = NULL;
	return (tmp);
}
