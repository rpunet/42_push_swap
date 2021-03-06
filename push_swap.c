/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:28:36 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:47:49 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc >= 2)
		parse_argv(argv[1], &stack_a, NULL);
	if (argc > 2)
		add_argv(argc, argv, &stack_a);
	ft_sort_set(&stack_a, &stack_b);
	ft_clear_stack(&stack_a, &stack_b);
	return (0);
}
