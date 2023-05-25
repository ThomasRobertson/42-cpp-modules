#*************************************************************************** #
#                                                                              #
#            :::      ::::::::                                                 #
#          :+:      :+:    :+:                                                 #
#        +:+ +:+         +:+         Makefile v2.1                             #
#      +#+  +:+       +#+                                                      #
#    +#+#+#+#+#+   +#+               By: troberts <troberts@student.42.fr>     #
#         #+#    #+#                                                           #
#        ###   ########.fr                                                     #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              VARIABLE REFERENCE                              #
# **************************************************************************** #

NAME= account

CC= clang++
CPPFLAGS= -Wall -Werror -Wextra -g3 -std=c++98 $(INCLUDE)
LDFLAGS= 

INCLUDE = -I$(INCLUDE_DIR)

INCLUDE_DIR= ./
OBJ_DIR= obj/
SRC_DIR= ./

# **************************************************************************** #
#                                .C & .H FILES                                 #
# **************************************************************************** #

SRC_FILE=	\
			Account.cpp \
			tests.cpp

SRC=		$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ=		$(addprefix obj/, ${SRC_FILE:.cpp=.o})

# **************************************************************************** #
#                                HEADER CONFIG                                 #
# **************************************************************************** #

#                 # <-- start here         | <-- middle             # <-- stop here
HEADER_NAME 	= +                       CPP                       #

COLOR_RED		= \033[0;31m
COLOR_GREEN		= \033[0;32m
COLOR_YELLOW	= \033[0;33m
COLOR_BLUE		= \033[0;34m
COLOR_PURPLE	= \033[0;35m
COLOR_CYAN		= \033[0;36m
COLOR_WHITE		= \033[0;37m
COLOR_END		= \033[m

HEADER =		@echo "${COLOR_CYAN}\
				\n/* ************************************************************************** */\
				\n/*                                                                            */\
				\n/*            :::      ::::::::                                               */\
				\n/*          :+:      :+:    :+:                                               */\
				\n/*        +:+ +:+         +:${HEADER_NAME}*/\
				\n/*      +\#+  +:+       +\#+                                                    */\
				\n/*    +\#+\#+\#+\#+\#+   +\#+                    <troberts@student.42.fr>           */\
				\n/*         \#+\#    \#+\#                                                         */\
				\n/*        \#\#\#   \#\#\#\#\#\#\#\#.fr                                                   */\
				\n/*                                                                            */\
				\n/* ************************************************************************** */\
				\n \
				\n${COLOR_END}"

HEADER_VAR =	@echo "${COLOR_CYAN}\
				\n \
				BINARY NAME: $(NAME) \
				\n CC: $(CC) \
				\n CPPFLAGS: $(CPPFLAGS) \
				\n LDFLAGS: $(LDFLAGS) \
				\n${COLOR_END}"

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): FORCE header
	$(HEADER_VAR)
	@echo -n "${COLOR_YELLOW}Compiling : \n[${COLOR_END}"
	@$(MAKE) --no-print-directory --silent $(OBJ)
	@echo -n "${COLOR_YELLOW}]\n\n${COLOR_END}"
	@echo -n "${COLOR_GREEN}Linking : "
	@$(CC) -o $@ $(OBJ) $(LDFLAGS)
	@echo "${COLOR_GREEN}Done. ${COLOR_END}"

FORCE: ;

bonus: $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo -n "${COLOR_YELLOW}#${COLOR_END}"
	@mkdir -p $(@D)
	@$(CC) $(CPPFLAGS) -c $< -o $@

reobj: FORCE header cleanobj
	$(HEADER_VAR)
	@echo -n "${COLOR_YELLOW}Compiling : \n[${COLOR_END}"
	@$(MAKE) --no-print-directory --silent $(OBJ)
	@echo -n "${COLOR_YELLOW}]\n\n${COLOR_END}"
	@echo -n "${COLOR_GREEN}Linking : "
	@$(CC) -o $@ $(OBJ) $(LDFLAGS)
	@echo "${COLOR_GREEN}Done. ${COLOR_END}"

header:
	$(HEADER)

cleanobj:
	@rm -f $(OBJ)

cleanobjdir: cleanobj
	@rm -rf $(OBJ_DIR)

clean: header
	@echo "${COLOR_RED}Removing objects.${COLOR_END}"
	@$(MAKE) --no-print-directory --silent cleanobj
	@echo "${COLOR_RED}Removing object directory.${COLOR_END}"
	@$(MAKE) --no-print-directory --silent cleanobjdir

fclean: clean
	@echo "${COLOR_RED}Removing binary file.${COLOR_END}"
	@rm -f $(NAME) $(NAME_BONUS)

re: header fclean all

# reobj: cleanobj
# 	make -C .

.PHONY: all clean fclean re reobj header cleanobj bonus FORCE cleanobjdir