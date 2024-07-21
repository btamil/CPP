# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:35:43 by tponnusa          #+#    #+#              #
#    Updated: 2024/03/20 14:41:39 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Own_Sed

CC		= c++

CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp

OBJ     =  $(SRC:.cpp=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all 	:	$(NAME)

clean	: 
			rm -f $(OBJ)

fclean	: 	clean
			rm -f $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re