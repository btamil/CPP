# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 13:13:51 by tponnusa          #+#    #+#              #
#    Updated: 2024/05/27 13:13:54 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc

CPP		= c++

CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp BitCoinExchange.cpp

OBJ     =  $(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): 	$(OBJ)
			$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

all 	:	$(NAME)

clean	: 
			rm -f $(OBJ)

fclean	: 	clean
			rm -f $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re