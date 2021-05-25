# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 21:45:10 by asirenko          #+#    #+#              #
#    Updated: 2019/12/07 21:48:40 by asirenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

OBJ_DIR = ./obj/

SRC =	Enemy.cpp \
		EnemyHorde.cpp \
		Game.cpp \
		main.cpp \
		Player.cpp \
		Proj.cpp \
		ProjHorde.cpp \
		Star.cpp \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

FLAGS = -Wall -Wextra -Werror

NCURSESL = -lncurses

COMPILER = g++ $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(COMPILER) $(NCURSESL) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
$(OBJ_DIR)%.o: %.cpp
	$(COMPILER) -c $< -o $@

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re