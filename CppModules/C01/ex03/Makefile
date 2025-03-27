CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = attack
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re : fclean all

.PHONY: all clean