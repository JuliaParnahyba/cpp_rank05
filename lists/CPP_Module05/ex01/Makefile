# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 00:00:00 by jparnahy          #+#    #+#              #
#    Updated: 2026/05/23 00:00:00 by jparnahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRC = main.cpp \
	Bureaucrat.cpp \
	Form.cpp

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

MAKEFLAGS += --no-print-directory

RM = rm -f
MKDIR = mkdir -p

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CPP) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
