CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -lncurses
SOURCES = main.cpp

OBJS = $(SOURCES:.cpp=.o)
NAME = ft_retro

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
