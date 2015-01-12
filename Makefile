CXX = g++
RM = /bin/rm
CXXFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lncurses

NAME = ft_retro

SRC = ACharacter.cpp \
	AGameEntity.cpp \
	CollisionChecker.cpp \
	Console.cpp \
	DisplaySprite.cpp \
	Enemy.cpp \
	EnemySpawner.cpp \
	Fps.cpp \
	Game.cpp \
	Hitbox.cpp \
	InputController.cpp \
	Interval.cpp \
	Missile.cpp \
	MoveController.cpp \
	Obstacle.cpp \
	Pattern.cpp \
	Player.cpp \
	Position.cpp \
	Sprite.cpp \
	Window.cpp \
	main.cpp

HEADER = ACharacter.hpp \
	AGameEntity.hpp \
	CollisionChecker.hpp \
	Console.hpp \
	DisplaySprite.hpp \
	Enemy.hpp \
	EnemySpawner.hpp \
	Fps.hpp \
	Game.hpp \
	Hitbox.hpp \
	InputController.hpp \
	Interval.hpp \
	Missile.hpp \
	MoveController.hpp \
	Obstacle.hpp \
	Pattern.hpp \
	Player.hpp \
	Position.hpp \
	Sprite.hpp \
	Window.hpp

OFILES = $(patsubst %.cpp,%.o, $(SRC))

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Building $(NAME)"
	@$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Deletion of building files"
	@$(RM) -f $(OFILES)

fclean: clean
	@echo "Deletion of $(NAME)"
	@$(RM) -f $(NAME)

re: fclean all

test:
	@echo $(SRC)
	@echo $(OFILES)
	@echo $(HEADER)
