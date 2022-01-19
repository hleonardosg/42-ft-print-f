# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 18:33:58 by coder             #+#    #+#              #
#    Updated: 2022/01/16 18:35:09 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRCS =	ft_printf_utils.c \
		ft_printf.c
FLAGS = -Wall -Wextra -Werror
OBJS =	$(SRCS:%.c=%.o)
CC = 	clang

all: $(NAME)

$(OBJS): %.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	@echo "$< has been successfully compiled"

$(NAME): $(OBJS)
	ar rcs $(NAME) $^
	@echo "$(NAME) has been successfully compiled"

clean:
	rm -rf $(OBJS)
	@echo "Clean done successfully"	

fclean: clean
	rm -rf $(NAME)
	@echo "Clean done successfully"	

re: fclean all

.PHONY: all clean fclean re