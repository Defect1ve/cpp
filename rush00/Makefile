# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 17:44:05 by ikotvits          #+#    #+#              #
#    Updated: 2018/07/17 17:44:06 by ikotvits         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

FLAGS = -Wall -Wextra -Werror 

SRCS = Game.cpp Enemy.cpp Spaceship.cpp ASpaceObject.cpp main.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ clang++ $(OBJ) -o $(NAME) -I . -lncurses


clean:
	@ rm -f $(OBJ)
	@ tput setaf 4; echo All object files have been deleted

fclean: clean
	@ rm -f $(NAME)
	@ tput setaf 5; echo Binary file has been deleted

re: fclean all

.PHONY: fclean clean all re