# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lda-silv <lda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 06:17:39 by lda-silv          #+#    #+#              #
#    Updated: 2022/01/19 06:17:39 by lda-silv         ###   ########.fr        #
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