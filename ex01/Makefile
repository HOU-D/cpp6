NAME = seria

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all