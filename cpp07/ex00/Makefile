# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 19:38:08 by tponnusa          #+#    #+#              #
#    Updated: 2024/05/21 19:39:06 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Template

CPP		= c++

CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp

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