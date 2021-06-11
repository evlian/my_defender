##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for libmy.a
##
SRC = $(shell find . -type f -name '*.c')

OBJ = $(SRC:.c=.o)

NAMEL = libmy.a

NAMEI = my.h

all: $(NAMEL)

$(NAMEL): $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAMEL) $(OBJ)
	make clean

clean : $(shell rm -f $(OBJ))