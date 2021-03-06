/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:28:36 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/06 18:29:29 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	g_print = 0;

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return (0);
	if (argc >= 2)
		parse_argv(argv[1], &stack_a);
	if (argc > 2)
		add_argv(argc, argv, &stack_a);
	//print_stack(stack_a);
	ft_sort_set(&stack_a, &stack_b);
	//print_stack(stack_a);
	ft_clear_stack(&stack_a, &stack_b);
	return (0);
}

/*
t_list * SortList1(t_list * pList)
{
    // zero or one element in list
    if (pList == NULL || pList->next == NULL)
        return pList;
    // head is the first element of resulting sorted list
    t_list * head = NULL;
    while (pList != NULL) {
        t_list * current = pList;
        pList = pList->next;
        if (head == NULL ||*(int *)(current->content) < *(int *)(head->content))
		{
            // insert into the head of the sorted list
            // or as the first element into an empty sorted list
            current->next = head;
            head = current;
        } else {
            // insert current element into proper position in non-empty sorted list
            t_list * p = head;
            while (p != NULL) {
                if (p->next == NULL || *(int *)(current->content) < *(int *)(p->next->content))// last element of the sorted list// middle of the list
                {
                    // insert into middle of the sorted list or as the last element
                    current->next = p->next;
                    p->next = current;
                    break; // done
                }
                p = p->next;
            }
        }
    }
    return head;
}
 */

/* void	ft_bubble_sort(t_list *s, int size)
{
	int	*p;
	int	i;
	int	j;

	p = (int *)s->content;
	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (p[j] < p[i])
				ft_swap(&p[j], &p[i]);
			j++;
		}
		j = 0;
		i++;
	}
}

 */
