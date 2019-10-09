# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 15:43:38 by asantiag          #+#    #+#              #
#    Updated: 2019/10/09 18:05:07 by asantiag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = convert.c ft_printf.c libft.c

OBJECT = $(SRC:.c=.o)

OPTIONS = -c -I ./includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) $(OPTIONS)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
			rm -f $(OBJECT)

fclean: clean 
			rm -f $(NAME)

re: fclean all
