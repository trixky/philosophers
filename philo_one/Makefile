NAME = philosopher_one

PTHREAD = -pthread

SRCS =	./srcs/error_exit.c\
		./srcs/init_1.c\
		./srcs/main.c\
		./srcs/thread_tools.c\
		./srcs/check_end.c\
		./srcs/get_time.c\
		./srcs/init_2.c\
		./srcs/parser.c\
		./srcs/thread.c\
		./srcs/tools.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

%.o:%.c
	$(CC) $(PTHREAD) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(PTHREAD) $(FLAGS) $(SRCS) -o $(NAME)

.PHONY : clean all fclean re bonus

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
