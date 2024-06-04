# SHELL = /bin/zsh

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCES =	push_swap.c\
			utils.c\
			doubly_linked_list.c

OBJECTS := $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "created $(NAME)"

# use: dorker make valgrind
valgrind :
	@rm -Rf ./dorker
	@mkdir ./dorker
	$(CC) -g $(SOURCES) -o ./dorker/dorker_$(NAME)
	valgrind --leak-check=full ./dorker/dorker_push_swap

debug :
	-mkdir ./debug
	$(CC) -g $(SOURCES) -o ./debug/debug_$(NAME)
	./debug/debug_$(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
clean :
	@rm -f *.o
	@echo "removed object files"
fclean : clean
	@rm -f $(NAME)
	@echo "removed $(NAME)"
re : fclean all

.PHONY : clean fclean re all debug dorker valgrind
