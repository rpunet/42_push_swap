/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:29:06 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/04 14:02:14 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftPLUS/includes/libft.h"

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
 */
#define BUFF_SIZE	64
/*
enum				e_instr{
	sa,
	sb,
	ss,
	pa,
	pb,
}; */

char	*instr[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb"/* ,
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrv" */
};

void	sb(t_list **a, t_list **b);
void	sa(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	(*instructions[])(t_list **a, t_list **b) = {
	&sa,
	&sb,
	&ss,
	&pa,
	&pb
};

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

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (new && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}


t_list	*ft_lstpop(t_list **top)
{
	t_list	*tmp;

	if (*top == NULL)
		return NULL;
	tmp = *top;
	*top = (*top)->next;
	tmp->next = NULL;
	return (tmp);
}

void	sb(t_list **a, t_list **b)
{
	if (a && b)
		ft_lstswap(b);
}

void	sa(t_list **a, t_list **b)
{
	if (a && b)
		ft_lstswap(a);
}

void	ss(t_list **a, t_list **b)
{
	ft_lstswap(a);
	ft_lstswap(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = ft_lstpop(b);
		ft_lstadd_front(a, tmp);
	}
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a)
	{
		tmp = ft_lstpop(a);
		ft_lstadd_front(b, tmp);
	}
}

int		ft_check_sort(t_list *a, t_list *b)
{
	if (b || !a || !a->next)
		return (0);
	while (a->next)
	{
		if (*(int*)(a->content) > *(int*)(a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}


void	del(void *content)
{
	if (content)
		free(content);
}


int		main(int argc, char **argv)
{
	int		i = 1;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*aux;
	int		*num;
	char	*line;
	void	(*del_ptr)(void*);
	del_ptr = del;

	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		num = malloc(sizeof(int));
		*num = ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(num));
		i++;
	}

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, ""))
			break;
		i = 0;
		while (i < 5)
		{
			if (!ft_strcmp(line, instr[i]))
			{
				(*instructions[i])(&stack_a, &stack_b);				//otra manera buena de hacer este while es pasar como indice [ps] la propia instrucción definida con un num
				break;
			}
			i++;
		}
		aux = stack_a;
		while (stack_a != NULL)
		{
			ft_printf("%d ", *(int*)(stack_a->content));
			stack_a = stack_a->next;
		}
		ft_printf("\n");
		stack_a = aux;
	}
	free(line);
	aux = stack_a;
	while (aux != NULL)
	{
		ft_printf("%d ", *(int*)(aux->content));
		aux = aux->next;
	}
	ft_printf("--");
	t_list	*auxb = stack_b;
	while (stack_b != NULL)
	{
		ft_printf("%d ", *(int*)(stack_b->content));
		stack_b = stack_b->next;
	}
	ft_printf("\n");

	if (ft_check_sort(stack_a, auxb))
		ft_printf("OK\n");
	else
		ft_printf("KOOOO\n");
	ft_lstclear(&stack_a, (*del_ptr));
	ft_lstclear(&stack_b, (*del_ptr));
	return (0);
}

