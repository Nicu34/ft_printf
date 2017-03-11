# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/13 20:20:28 by nmuresan          #+#    #+#              #
#    Updated: 2016/02/16 20:25:28 by nmuresan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ 
	gcc -c $(SRCS) libft/*.c
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
