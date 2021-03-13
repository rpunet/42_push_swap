/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:09:35 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:18:38 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_short_buff(t_buff *buffer, int cont, int instr)
{
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
	while (cont--)
		print_val(instr);
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
