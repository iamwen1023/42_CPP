SRC			= main.cpp Fixed.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= now
FLAGS		= -Wall -Wextra -Werror -std=c++98 
CC			= c++
RM			= rm -rf

ifeq (${DEBUG}, 1)
    FLAGS    += -fsanitize=thread
endif

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $@ $(OBJ) $(FLAGS)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM)  $(NAME)

re:    fclean all

.PHONY:     all clean fclean re