# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:47:54 by tponnusa          #+#    #+#              #
#    Updated: 2024/03/13 15:47:58 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Moar_brainz

CC		= c++

CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp Zombie.cpp zombieHorde.cpp

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