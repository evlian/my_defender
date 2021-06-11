##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for pushswap
##

NAME = my_defender

CC = gcc

RM = rm -f

SRC = ./src/main

LIBFLAG = -L ./lib/my/ -lmy -I./include/ -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

all: $(NAME)

$(NAME):
	make -f lib/my/Makefile
	make clean -f lib/my/Makefile
	mv ./libmy.a ./lib/my/
	$(CC) $(SRC).c -o $(SRC).o -c
	$(CC) -o $(NAME) $(SRC).o $(LIBFLAG)
	make clean
clean:
	$(RM) $(OBJS)
	$(RM) *.o
	$(RM) ./src/*.o

fclean: clean
	make clean
	$(RM) $(NAME)

re: fclean all