##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## projet solo 1
##

all:
	$(MAKE) -C ./antman/
	$(MAKE) -C ./giantman/

clean:
	$(MAKE) -C ./antman/ clean
	$(MAKE) -C ./giantman/ clean

fclean:	clean
	$(MAKE) -C ./antman/ fclean
	$(MAKE) -C ./giantman/ fclean

re:	fclean all

.Phony: all clean fclean re
