##
## Makefile for List in /home/lerest_m/Programmation/C/ChainedList/
##
## Made by Mewen Le Reste
## Login   <mewen.lereste@epitech.eu>
##
## Started on  Tue Apr 18 15:11:34 2017 Mewen Le Reste
## Last update Tue Apr 18 15:23:25 2017 Mewen Le Reste
##

SRC	= list.c \
			listAdd.c \
			listDel.c \
			listGet.c \
			listSort.c

TESTSRC = test.c

OBJ	= $(SRC:.c=.o)

TESTOBJ = $(TESTSRC:.c=.o)

NAME	= list.a

TESTNAME = test

CFLAGS	= -W -Wall -Werror -pedantic -ansi

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(TESTNAME): $(TESTOBJ)
	gcc -o $(TESTNAME) $(TESTOBJ) $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(TESTOBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)

re: fclean all

.PHONY: all clean fclean re
