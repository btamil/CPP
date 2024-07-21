# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:35:07 by tponnusa          #+#    #+#              #
#    Updated: 2024/03/13 16:35:08 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Unnecessary_Violence

CC		= c++

CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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