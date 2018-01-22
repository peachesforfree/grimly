NAME = grimly

CC = gcc

FLAGS = -Wall -Werror -Wextra

FILES = main.c \
		grimly.c \
		heat_map.c

LIBS = libft/libft.a

INCLUDE = -I.

OBJS = $(SRCS:.c=.o)

all: $(NAME)
		
$(NAME):
	make -C libft 
	$(CC) $(FLAGS) $(FILES) $(INCLUDE) $(LIBS)

fclean:
	$(RM) $(NAME)
	make -C libft fclean

clean: fclean
	make -C libft clean

re: fclean all