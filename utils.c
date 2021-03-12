/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:18:08 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 12:26:46 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi_error(const char *str)
{
	int 		sign;
	ssize_t 		num;

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

void	parse_argv(char *arg, t_list **a, int *bonus_opt)
{
	char	**args;
	char	**aux;
	int		*n;

	if (!ft_strcmp(arg, "-v"))
	{
		*bonus_opt = 1;
		return ;
	}
	args = ft_split(arg, ' ');
	aux = args;
	while (*args)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi_error(*args);
		check_dup(*n, *a);
		ft_lstadd_back(a, ft_lstnew(n));
		free(*args);
		args++;
	}
	free(aux);
}

void	add_argv(int argc, char **argv, t_list **a)
{
	int	i;
	int	*num;

	i = 2;
	while (i < argc)
	{
		num = malloc(sizeof(int));
		*num = ft_atoi_error(argv[i]);
		check_dup(*num, *a);
		ft_lstadd_back(a, ft_lstnew(num));
		i++;
	}
}

void	check_dup(int n, t_list *a)
{
	while (a)
	{
		if (*(int *)(a->content) == n)
			ft_exit("Error\n");
		a = a->next;
	}
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

