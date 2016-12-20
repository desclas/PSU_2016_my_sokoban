##
## Makefile for  in /home/mathias/Bureau/soko
## 
## Made by Mathias
## Login   <mathias.descoin@epitech.eu@epitech.net>
## 
## Started on  Tue Dec 20 22:24:10 2016 Mathias
## Last update Tue Dec 20 22:28:40 2016 Mathias
##

SRC	=	part5.c	\
		part4.c	\
		part3.c	\
		part2.c	\
		part1.c	\
		soko.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
