# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 17:35:44 by jparnahy          #+#    #+#              #
#    Updated: 2026/05/23 17:57:08 by jparnahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#The executable name
NAME = replace_me

#Directories
SRC_DIR = src
OBJ_DIR = obj
# Include directory. Remove -I$(INC_DIR) from FLAGS if the exercise has no headers directory.
INC_DIR = includes

#Source and objects files
# Add all .cpp files here.
SRC = main.cpp

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

#toolchain
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

#quiet recursive make ("entering/leaving directory")
MAKEFLAGS += --no-print-directory

#Valgrind flags
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --track-fds=yes

#Tools
#clear the implicit rules
RM = rm -f
#folder creat
MKDIR = mkdir -p

# Colors for the compilation
RESET = \033[0m
GREEN = \033[1;32m
GREEN_MARK = \033[0;42m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RED_MARK = \033[0;41m
CYAN = \033[1;36m
BOLD = \033[1m
ITALIC = \033[3m

# Raiboow colors
RE = \033[38;5;196m
OR = \033[38;5;208m
YE = \033[38;5;226m
GR = \033[38;5;46m
BL = \033[38;5;21m
IN = \033[38;5;93m
VI = \033[38;5;201m

# Emojis
CHECK = ✅
CROSS = ❌
ARROW = ➜
FLGS = 🏳️
GEAR = ⚙️
BOX = 📦
NOR = 🔎

# Progress bar lenght
PROGRESS_BAR_LENGTH = 50
PROGRESS_BAR_LENGTH_CLEAN = 30

#Rules
all: $(NAME)

#compiling
$(NAME): $(OBJ)
	@echo
	@echo "$(CYAN)$(GEAR) Linking $(NAME)...$(RESET)"
	@$(CPP) $(FLAGS) -o $@ $^
	@$(MAKE) progress COLOR="$(GREEN_MARK)" LENGTH="$(PROGRESS_BAR_LENGTH)" SPEED="0.03"
	@echo "$(FLGS) $(YELLOW)Flags used: $(FLAGS)$(RESET)"
	@echo "$(ARROW) $(CYAN)Executable created: ./$(NAME)$(RESET)"
	@echo "$(BOLD)$(GREEN)$(CHECK) Compilation complete!$(RESET)"
	@echo

#compiles each .cpp into .o inside the obj/ folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "$(BLUE)$(GEAR) Compiling $<...$(RESET)"
	@$(CPP) $(FLAGS) -c $< -o $@

#ensure obj dir exists
$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

#progress bar
progress:
	@for i in $$(seq 1 $(LENGTH)); do \
		printf "$(COLOR)=$(RESET)"; \
		sleep $(SPEED); \
	done; \
	echo "$(GREEN)  $(CHECK) 100%$(RESET)"

#object cleaning
clean:
	@echo "$(RED)$(CROSS) Removing object files and directory...$(RESET)"
	@$(MAKE) progress COLOR="$(RED_MARK)" LENGTH="$(PROGRESS_BAR_LENGTH_CLEAN)" SPEED="0.015"
	@$(RM) $(OBJ)
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(YELLOW)  $(BOX) Object files and directory removed.$(RESET)"
	@echo

#object and executable cleaning
fclean: clean
	@echo "$(RED)$(CROSS) Removing executable... $(RESET)"
	@$(MAKE) progress COLOR="$(RED_MARK)" LENGTH="$(PROGRESS_BAR_LENGTH_CLEAN)" SPEED="0.02"
	@$(RM) $(NAME)
	@echo "$(YELLOW)  $(GEAR) Executable removed.$(RESET)"
	@echo

#executable cleaning
eclean: 
	@echo "$(RED)$(CROSS) Removing executable... $(RESET)"
	@$(MAKE) progress COLOR="$(RED_MARK)" LENGTH="$(PROGRESS_BAR_LENGTH_CLEAN)" SPEED="0.01"
	@$(RM) $(NAME)
	@echo "$(YELLOW)  $(GEAR) Executable removed.$(RESET)"
	@echo

#rebuild
re: fclean all

#re exec
rerun: re run

#run
run: $(NAME)
	@./$(NAME)

#valgrind
hell: re
	@echo "$(RED)🔍 Running Valgrind...$(RESET)"
	@$(VALGRIND) ./$(NAME)

#to avoid conflits with files named clean, fclean and re
.PHONY: all clean fclean eclean re rerun run hell progress
