/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:29:06 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 13:30:19 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*g_instr[] = {
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr"
};

void	(*g_instructions[])(t_list **a, t_list **b, int print) = {
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

void	exec_command(t_list **a, t_list **b, int bonus_opt)
{
	char	*line;
	int		i;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, ""))
			break ;
		i = 0;
		while (i < OPERATIONS)
		{
			if (!ft_strcmp(line, g_instr[i]))
			{
				(*g_instructions[i])(a, b, 0);
				break ;
			}
			i++;
		}
		check_instr(i, line, a, b);
		if (bonus_opt)
			print_stack(*a);
		free(line);
	}
	free(line);
}

void	check_instr(int inum, char *line, t_list **a, t_list **b)
{
	if (inum == OPERATIONS)
	{
		ft_clear_stack(a, b);
		free(line);
		ft_exit("Error\n");
	}
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		bonus_opt;

	stack_a = NULL;
	stack_b = NULL;
	bonus_opt = 0;
	if (argc < 2)
		return (0);
	if (argc >= 2)
		parse_argv(argv[1], &stack_a, &bonus_opt);
	if (argc > 2)
		add_argv(argc, argv, &stack_a);
	exec_command(&stack_a, &stack_b, bonus_opt);
	if (ft_check_sort(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (bonus_opt)
		print_stack(stack_a);
	ft_clear_stack(&stack_a, &stack_b);
	return (0);
}
