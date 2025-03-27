CC = g++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
TARGET = main
SRC = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp Intern.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
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
	rm -f shrubbery.txt

re : fclean all

.PHONY: all clean