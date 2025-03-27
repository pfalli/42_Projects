
NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = 	ft_print_char.c \
		ft_print_string.c \
		ft_print_nbr.c \
		ft_print_u.c \
		ft_print_hexa.c \
		ft_print_uphexa.c \
		ft_print_percentage.c \
		ft_print_ptr.c \
		ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFTNAME):
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
#	mv $(LIBFTNAME) $(NAME)

$(NAME): $(LIBFTNAME) $(OBJS)
	cp $(LIBFTNAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(LIBFTNAME)
	make -C $(LIBFTDIR) clean

#	makelibft:
#		make -C $(LIBFTDIR)
#		cp $(LIBFTDIR)/$(LIBFTNAME) .
#		mv $(LIBFTNAME) $(NAME)
#	
#	$(NAME): makelibft $(OBJS)
#		ar -rcs $(NAME) $(OBJS)
#	
#	clean:
#		rm -f $(OBJS)
#		cd $(LIBFTDIR) && make clean
	
fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	
re: fclean all
