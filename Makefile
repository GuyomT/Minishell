##
## EPITECH PROJECT, 2021
## B-MAT-100-NAN-1-1-105torus-guillaume.terriere
## File description:
## Makefile
##

CC = gcc

FILES = main.c\
		print.c\
		init_list.c\
		my_utils_str.c\
		search_command.c\
		my_getnbr.c\
		my_builtin.c\
		my_builtin_cd.c\
		my_execve.c\
		utils_env.c\
		my_str_to_tab.c\
		my_clean_str.c\

SRC = $(FILES:%=src/%)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wshadow -Wextra -Iinclude

LDFLAGS = -L lib/my -lmy

RM = rm -f

NAME = mysh

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lm $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug        :        CFLAGS += -g
debug        :        re

.PHONY: all clean fclean re debug