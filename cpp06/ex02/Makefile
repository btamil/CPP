# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 14:07:57 by tponnusa          #+#    #+#              #
#    Updated: 2024/05/21 14:43:36 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= DynamicCast

CPP		= c++

CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp Base.cpp

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