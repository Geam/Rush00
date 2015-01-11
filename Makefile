CC = /usr/bin/g++
RM = /bin/rm
CFLAGS = -Wall -Wextra Wno-used -Werror -I $(HPATH)
LDFLAGS = -lncurses

NAME = ft_retro

SRC = ACharacter.cpp \
	AGameEntity.cpp \
	CollisionChecker.cpp \
	Enemy.cpp \
	Fps.cpp \
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
Enemy.hpp \
Fps.hpp \
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
	@$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	@echo "Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Deletion of building files"
	@$(RM) -f $(OFILES)

fclean: clean
	@echo "Deletion of $(NAME)"
	@$(RM) -f $(NAME)

re: fclean all




