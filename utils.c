/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:18:08 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:33:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_error(const char *str)
{
	int		sign;
	ssize_t num;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
	*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_exit("Error\n");
		}
		num = 10 * num + *str - '0';
		str++;
	}
	if (num < INT_MIN || num > __INT_MAX__)
		ft_exit("Error\n");
	return (sign * (int)num);
}

void	print_stack(t_list *a)
{
	while (a != NULL)
	{
		ft_printf("%d ", *(int*)(a->content));
		a = a->next;
	}
	ft_printf("\n");
}

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void	del(void *content)
{
	if (content)
		free(content);
}

int		ft_check_sort(t_list *a, t_list *b)
{
	if (b || !a)
		return (0);
	if (!a->next)
		return (1);
	while (a->next)
	{
		if (*(int*)(a->content) > *(int*)(a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}
