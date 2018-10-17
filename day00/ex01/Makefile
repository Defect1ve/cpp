NAME = PhoneBook

FLAGS = -Wall -Wextra -Werror

INCLUDES = Contact.hpp PhoneBook.hpp

SRC = Contact.cpp PhoneBook.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	clang++ $(OBJ) -o $(NAME)

%.o: %.cpp
	@ clang++ $(FLAGS) -o $@ -c $< -I .

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all