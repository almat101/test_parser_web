NAME = webserver
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes
RM = rm -rf

SRC = $(wildcard srcs/*.cpp)

HDRS = $(wildcard includes/*.hpp)

OBJ = $(SRC:srcs/%.cpp=obj/%.o)

all: $(NAME)

obj/%.o: srcs/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HDRS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
