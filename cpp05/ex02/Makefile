# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 14:58:27 by tponnusa          #+#    #+#              #
#    Updated: 2024/05/13 14:58:29 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Multiple_Forms

CPP		= c++

CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

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
