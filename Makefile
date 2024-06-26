NAME = push_swap
CC = cc
# CFLAGS = -Wall -Werror -Wextra
SOURCES =	./push_swap.c\
			./inits.c\
			./utils.c\
			./doubly_linked_list.c\
			./process_input.c\
			./free_mem.c\
			./termination.c\
			./rules_push.c\
			./rules_swap.c\
			./rules_rotate.c\
			./rules_rev_rotate.c\
			./the_game.c\
			./small_cases.c\
			./small_cases_utils.c\
			./radix_sort.c

OBJECTS := $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS) libft/libft.a
	@$(CC) -g $(CFLAGS) $(OBJECTS) ./libft/libft.a -o $(NAME)
	@echo "created $(NAME)"

%.o : %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@

libft/libft.a :
	@make -C ./libft/

all : $(NAME)
clean :
	@rm -f ./*.o
	@rm -f ./testing/*.o
	@rm -rf ./dorker ./debug
	@make -C ./libft clean
	@echo "removed object files"
fclean : clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@echo "removed $(NAME)"
re : fclean all

.PHONY : clean fclean re all
