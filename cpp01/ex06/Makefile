# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 13:19:54 by tponnusa          #+#    #+#              #
#    Updated: 2024/03/20 14:56:11 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Harl_Filter

CC		= c++

CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp Harl.cpp

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