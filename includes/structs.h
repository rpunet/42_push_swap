/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 23:19:13 by rpunet            #+#    #+#             */
/*   Updated: 2021/03/12 23:21:41 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**	stack  definition (to use it with Libft linked list functions)
**
**	typedef struct		s_list
**	{
**		void			*content;
**		struct s_list	*next;
**	}					t_list;
*/

typedef struct		s_buff
{
	int				val;
	struct s_buff	*next;
}					t_buff;

enum				e_instr{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

#endif
