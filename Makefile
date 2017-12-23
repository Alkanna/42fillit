# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshults <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 18:34:55 by dshults           #+#    #+#              #
#    Updated: 2017/12/23 21:03:19 by klouer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"
RUN_STRING	 = "Running"

COLL = $(shell export COLUMNS)
COL = $(shell echo $(COLUMNS))

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c	put.c	get.c	solve.c	tris.c	check_input.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LFT_PATH = ./includes/libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) libft" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";
	@make -C $(LFT_PATH)
	@gcc -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft
	@printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";
	@printf "%-60b%b" "$(OK_COLOR)Compilation successful." "$(NO_COLOR)\n"
	@printf "%-60b%b" "$(WARN_COLOR)Usage: ./fillit [mapfile] - Have fun !" "$(NO_COLOR)\n";

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@printf "%-60b%b" "$(COM_COLOR)$(RUN_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -rf $(NAME)
	@printf "%-60b%b" "$(COM_COLOR)$(RUN_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";

re: fclean all

help: environnement
	export COLUMNS
	echo $COLUMNS
	export COLUMNS && printf "%*s" "$$COLUMNS" | tr " " "-"
	@printf "%-60b%b" "$(WARN_COLOR)Authors   $(NO_COLOR): $(OK_COLOR)klouer" "$(NO_COLOR)\n"

environnement:
	@export COLUMNS; echo $$COLUMNS
