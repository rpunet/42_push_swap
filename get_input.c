/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:32:03 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:43:03 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
