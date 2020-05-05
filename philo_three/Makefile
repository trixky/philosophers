NAME = philosopher_three

PTHREAD = -pthread

SRCS =	./srcs/error_exit.c\
		./srcs/init_2.c\
		./srcs/processus_tools_2.c\
		./srcs/get_time.c\
		./srcs/main.c\
		./srcs/processus.c\
		./srcs/tools.c\
		./srcs/init_1.c\
		./srcs/parser.c\
		./srcs/processus_tools_1.c

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
