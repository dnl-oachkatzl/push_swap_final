NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3
SOURCES =	./sources/push_swap.c\
			./sources/inits.c\
			./sources/utils.c\
			./sources/doubly_linked_list.c\
			./sources/process_input.c\
			./sources/free_mem.c\
			./sources/termination.c\
			./sources/rules_push.c\
			./sources/rules_swap.c\
			./sources/rules_rotate.c\
			./sources/rules_rev_rotate.c\
			./sources/the_game.c\
			./sources/small_cases.c\
			./sources/small_cases_utils.c\
			./sources/radix_sort.c

OBJECTS := $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS) ./lib/libft/libft.a
	@$(CC) $(CFLAGS) $(OBJECTS) ./lib/libft/libft.a -o $(NAME)
	@echo "created $(NAME)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

lib/libft/libft.a :
	@make -C ./lib/libft/

all : $(NAME)
clean :
	@rm -f ./sources/*.o
	@make -C ./lib/libft clean
	@echo "removed object files"
fclean : clean
	@make -C ./lib/libft fclean
	@rm -f $(NAME)
	@echo "removed $(NAME)"
re : fclean all

.PHONY : clean fclean re all
