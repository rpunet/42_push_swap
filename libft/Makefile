# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 21:22:26 by rpunet            #+#    #+#              #
#    Updated: 2020/09/26 12:17:31 by rpunet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc
NORME		= norminette -R CheckForbiddenSourceHeader
HDIR		= -I ./includes
SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcpy.c ft_strclr.c ft_strnew.c
SRCS2		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCS3		= ft_max.c ft_min.c ft_pow.c ft_strnew.c ft_count_digit.c ft_sort_int.c ft_swap.c ft_abs.c
SRCSPRINT	= ft_printf.c ft_tracker.c flags.c ft_print_int.c ft_print_char.c ft_print_str.c ft_print_ptr.c ft_print_udec_int.c ft_print_hex.c ft_printf_utils.c
SRCSGNL		= get_next_line.c
OBJS		= $(SRCS:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
OBJS3		= $(SRCS3:.c=.o)
OBJSPRINT	= $(SRCSPRINT:.c=.o)
OBJSGNL		= $(SRCSGNL:.c=.o)

# ---------- Colors ------------

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED		= \033[1;31m
LIGHT_RED	= \033[1;31m
GREY		= \033[1;30m
DARK_GREY	= \033[30m
YELLOW		= \033[1;33m
PURPLE		= \033[1;35m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
COLOR_OFF	= \033[0m



all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS) $(SRCS2) $(SRCS3) $(addprefix ./ft_printf/, $(SRCSPRINT)) $(addprefix ./get_next_line/, $(SRCSGNL)) $(HDIR)
	@ar rcs $(NAME) $(OBJS) $(OBJS2) $(OBJS3) $(OBJSPRINT) $(OBJSGNL)
	@echo "$(CYAN)[libft.a done!]$(COLOR_OFF)"

norme: $(NORME) $(SRCS) $(SRCS2) $(SRCS3) $(addprefix ./ft_printf/, $(SRCSPRINT)) $(addprefix ./get_next_line/,$(SRCSGNL))

clean:
	@rm -f $(OBJS) $(OBJS2) $(OBJS3) $(OBJSPRINT) $(OBJSGNL)
	@echo "$(GREY)[libft objects removed]$(COLOR_OFF)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[libft cleared!]$(COLOR_OFF)"

re: fclean all


.PHONY: all clean fclean re
