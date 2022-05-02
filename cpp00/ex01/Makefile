INCS		= includes
SRC			= Contact.cpp PhoneBook.cpp main.cpp
OBJ			= $(SRC:.c=.o)
NAME		= phonebook
FLAGS		= -Wall -Wextra -Werror -std=c++98 -I${INCS}

ifeq (${DEBUG}, 1)
	FLAGS	+= -fsanitize=thread
endif

all: $(NAME)

$(NAME): $(OBJ)
		g++ -o $@ $(OBJ) $(FLAGS)

%.o: %.c
		cc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM)  $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re