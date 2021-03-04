# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 19:49:44 by rpunet            #+#    #+#              #
#    Updated: 2021/03/04 13:17:50 by rpunet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= checker
SRCS		= checker.c
LIBFT_PATH	= ../libftPLUS/


all: clean
	gcc -Wall -Wextra -Werror -g -fsanitize=address ${SRCS} -I . -L $(LIBFT_PATH) -lft -o ${NAME}

clean:
		@rm -f $(NAME)

