# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 19:49:44 by rpunet            #+#    #+#              #
#    Updated: 2021/03/12 21:03:00 by rpunet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_CH		= checker
NAME_PS 	= push_swap
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
CC			= gcc
SRCS		= operations.c operations2.c operations3.c utils.c lists.c sorts.c ft_quick_sort.c medium_sort.c operations_buffer.c buffer_utils.c get_input.c
SRCS_CH		= $(SRCS) checker.c
SRCS_PS		= $(SRCS) push_swap.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I./includes/ -I./libft/includes
LIBFT_DIR	= libft/

# ------------- colors -----------------

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED			= \033[1;31m
LIGHT_RED	= \033[1;31m
GREY		= \033[1;30m
DARK_GREY	= \033[30m
YELLOW		= \033[1;33m
PURPLE		= \033[1;35m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
COLOR_OFF	= \033[0m

all: $(NAME_PS) $(NAME_CH)

$(NAME_CH): $(OBJS_CH)
	@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) ${SRCS_CH}  -L $(LIBFT_DIR) -lft -o ${NAME_CH}
	@echo "$(GREEN)[Checker BUILT]$(COLOR_OFF)"

$(NAME_PS): $(OBJS_PS)
	@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) ${SRCS_PS}  -L $(LIBFT_DIR) -lft -o ${NAME_PS}
	@echo "$(GREEN)[Push_swap BUILT]$(COLOR_OFF)"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@echo "$(GREY)[Proyect objects removed]$(COLOR_OFF)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME_CH) $(NAME_PS)
	@echo "$(RED)[All cleared]$(COLOR_OFF)"

re: fclean all
