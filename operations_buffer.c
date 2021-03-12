/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:09:35 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 13:33:20 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	(*g_qsort_instr[])(t_list **a, t_list **b, int print) = {
	&sa,
	&sb,
	&ss,
	&pa,
	&pb,
	&ra,
	&rb,
	&rr,
	&rra,
	&rrb,
	&rrr
};

void	print_short_buff(t_buff *buffer)
{
	int cont = 0;
	int	instr = -1;

	while (buffer)
	{
		if (cont == 0 && (buffer->val == RA || buffer->val == RRA))
		{
			instr = buffer->val;
			cont++;
		}
		else if (buffer->val == PA || buffer->val == PB)
		{
			while (cont)
			{
				print_val(instr);
				cont--;
			}
			print_val(buffer->val);
		}
		else if (buffer->val == instr)
			cont++;
		else if (buffer->val != instr)
			cont--;

		buffer = buffer->next;
	}
	while (cont)
	{
		print_val(instr);
		cont--;
	}
}

void	print_val(int instr)
{
	if (instr == PA)
		ft_putstr_fd("pa\n", 1);
	else if (instr == PB)
		ft_putstr_fd("pb\n", 1);
	else if (instr == RA)
		ft_putstr_fd("ra\n", 1);
	else if (instr == RRA)
		ft_putstr_fd("rra\n", 1);
}

void	instr_to_buffer(int instr, t_buff **buffer, t_list **a, t_list **b)
{
	(*g_qsort_instr[instr])(a, b, 0);
	ft_buffadd_back(buffer, ft_buffnew(instr));
}


t_buff	*ft_bufflast(t_buff *buffer)
{
	if (!buffer)
		return (NULL);
	while (buffer->next != NULL)
		buffer = buffer->next;
	return (buffer);
}

void	ft_buffadd_back(t_buff **buffer, t_buff *new)
{
	t_buff	*last;

	if (!*buffer)
	{
		*buffer = new;
		return ;
	}
	if (!new || !buffer)
		return ;
	last = ft_bufflast(*buffer);
	last->next = new;
}

t_buff	*ft_buffnew(int inst)
{
	t_buff	*elem;

	if (!(elem = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	elem->val = inst;
	elem->next = NULL;
	return (elem);
}

void	ft_buffclear(t_buff **buffer)
{
	t_buff	*tmp;

	if (buffer == NULL || *buffer == NULL)
		return ;
	while (*buffer)
	{
		tmp = *buffer;
		*buffer = tmp->next;
		free(tmp);
	}
	*buffer = NULL;
}
