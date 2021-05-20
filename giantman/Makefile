##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## projet solo 1
##

SRC     =       $(wildcard *.c)

OBJ     =       $(SRC:.c=.o)

NAME	=	giantman

CFLAGS	=	-I ./include/

all:	lib/libmy $(OBJ)
	$(CC) -g -o $(NAME) $(OBJ) lib/my/libmy.a $(CFLAGS)
	$(RM) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) ./lib/my/*~
	$(MAKE) -C ./lib/my/ clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a
	$(MAKE) -C ./lib/my/ fclean

lib/libmy:
	$(MAKE) -C ./lib/my/

re:	fclean all

.Phony: all clean fclean re
