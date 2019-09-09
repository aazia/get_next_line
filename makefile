# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azkeever <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 10:36:43 by azkeever          #+#    #+#              #
#    Updated: 2019/09/09 14:20:17 by azkeever         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
HEADER = get_next_line.c tests/moul4.c
LIBRARY = libft/libft.a
SOURCE = get_next_line.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(HEADER) $(LIBRARY)

clean: 
	rm -f *.o *.swp *~ *.gch

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

