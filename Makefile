NAME	= 108trigo

CC	= gcc

RM	= rm -f

SRCS	= 	main.c	\
			108trigo.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -lm $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run:
				cd tests/ && $(MAKE)

.PHONY: all clean fclean re tests_run
