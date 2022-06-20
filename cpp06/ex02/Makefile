SRC			= main.cpp 
OBJ			= $(SRC:.cpp=.o)
NAME		= data
FLAGS		= -Wall -Wextra -Werror -std=c++98 
CC			= c++
RM			= rm -rf
SHADOW		= -Wshadow=local

ifeq (${DEBUG}, 1)
    FLAGS    += -fsanitize=thread
endif

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $@ $(OBJ) $(FLAGS) $(SHADOW)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM)  $(NAME)

re:    fclean 
	   make all

.PHONY:     all clean fclean re