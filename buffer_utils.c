/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:02:43 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 20:04:40 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
