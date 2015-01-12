#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/12 03:38:49 by mdelage           #+#    #+#              #
#    Updated: 2015/01/12 03:51:40 by mdelage          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CXX = /usr/local/bin/g++
MKDIR = /bin/mkdir
RM = /bin/rm
CXXFLAGS = -Wall -Wextra -Werror
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

OFILES = $(patsubst %.cpp,%.o, $(SRC))

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Building $(NAME)"
	@$(CXX) $(LDFLAGS) $^ -o $@

$(OPATH)/ACharacter.o: ACharacter.cpp ACharacter.hpp AGameEntity.hpp \
	Console.hpp Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp \
	Missile.hpp Pattern.hpp MoveController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/AGameEntity.o: AGameEntity.cpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/CollisionChecker.o: CollisionChecker.cpp CollisionChecker.hpp \
	AGameEntity.hpp Console.hpp Position.hpp Hitbox.hpp Sprite.hpp \
	DisplaySprite.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Console.o: Console.cpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/DisplaySprite.o: DisplaySprite.cpp DisplaySprite.hpp Position.hpp \
	Sprite.hpp Console.hpp Position.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Enemy.o: Enemy.cpp Enemy.hpp ACharacter.hpp AGameEntity.hpp \
	Console.hpp Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp \
	Missile.hpp Pattern.hpp MoveController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/EnemySpawner.o: EnemySpawner.cpp EnemySpawner.hpp Enemy.hpp \
	ACharacter.hpp AGameEntity.hpp Console.hpp Position.hpp Hitbox.hpp \
	Sprite.hpp DisplaySprite.hpp Missile.hpp  Pattern.hpp MoveController.hpp \
	 Window.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Fps.o: Fps.cpp Fps.hpp Interval.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Game.o: Game.cpp Game.hpp Player.hpp ACharacter.hpp AGameEntity.hpp \
	Console.hpp Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp \
	Missile.hpp Pattern.hpp MoveController.hpp InputController.hpp \
	CollisionChecker.hpp EnemySpawner.hpp Enemy.hpp Window.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Hitbox.o: Hitbox.cpp Hitbox.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/InputController.o: InputController.cpp InputController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Interval.o: Interval.cpp Interval.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Missile.o: Missile.cpp Missile.hpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp Pattern.hpp \
	MoveController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/MoveController.o: MoveController.cpp MoveController.hpp Position.hpp \
	Pattern.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Obstacle.o: Obstacle.cpp Obstacle.hpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Pattern.o: Pattern.cpp Pattern.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Player.o: Player.cpp ACharacter.hpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp Missile.hpp \
	Pattern.hpp MoveController.hpp Player.hpp ACharacter.hpp InputController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Position.o: Position.cpp Position.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Sprite.o: Sprite.cpp Sprite.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/Window.o: Window.cpp Window.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OPATH)/main.o: main.cpp Window.hpp Console.hpp Interval.hpp Fps.hpp \
	Interval.hpp Position.hpp DisplaySprite.hpp Position.hpp Sprite.hpp \
	AGameEntity.hpp Hitbox.hpp DisplaySprite.hpp Game.hpp Player.hpp \
	ACharacter.hpp AGameEntity.hpp Missile.hpp Pattern.hpp MoveController.hpp \
	InputController.hpp CollisionChecker.hpp EnemySpawner.hpp Enemy.hpp \
	Window.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Deletion of building files"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "Deletion of $(NAME)"
	@$(RM) -f $(NAME)

re: fclean all
