# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 05:35:05 by sduprey           #+#    #+#              #
#*   Updated: 2016/01/01 04:25:02 by sduprey          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = ft_printf.c \
	  get_val.c \
	  parse.c \
	  exception.c \
	  list.c \
	  misc.c \
	  funcArray.c \
	  main.c

SRCDIR = src/
OBJDIR = obj/

NO_COLOR = "\033[0;0m"
CC_COLOR = "\033[0;33m"
EX_COLOR = "\033[0;32m"
PX_COLOR = "\033[4;37m"
DE_COLOR = "\033[0;31m"

CC_STR = $(CC_COLOR)[CC]$(NO_COLOR)
EX_STR = $(EX_COLOR)$(NAME)$(NO_COLOR)
PX_STR = $(PX_COLOR)Binary compiled successfully$(NO_COLOR)
DE_STR = $(DE_COLOR)Remove$(NO_COLOR)

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC = clang

INC = -I ./inc -I libft/includes

LIB = -L libft -lft

CFLAGS = -g -Wall -Werror -Wextra

RM = rm -rf

all: lft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -lncurses -o $(NAME) $^ $(LIB)
	@echo ""
	@echo $(PX_STR) : $(EX_STR)
	@echo ""

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@echo $(CC_STR) $*

lft:
	@make -C libft

clean:
	@$(RM) $(OBJDIR)
	@echo $(DE_STR) objects

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo $(DE_STR) $(NAME)

re: fclean all

norm:
	@norminette **/*.[ch]

ex: re
	make clean
	./$(NAME)
