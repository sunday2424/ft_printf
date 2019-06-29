# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junpark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 23:54:12 by junpark           #+#    #+#              #
#    Updated: 2019/06/11 03:03:13 by junpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

INCLUDES = libft.h ft_printf.h

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC) -I$(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
