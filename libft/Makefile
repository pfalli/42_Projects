NAME =	libft.a

SRC	=	$(addsuffix .c, \
				 ft_isalpha \
				 ft_isdigit \
				 ft_isalnum \
				 ft_isascii \
				 ft_isprint \
				 ft_strlen \
				 ft_memset \
				 ft_bzero \
				 ft_memcpy \
				 ft_strlen \
				 ft_strlcpy \
				 ft_strlcat \
				 ft_memmove \
				 ft_memchr \
				 ft_strnstr \
				 ft_strrchr \
				 ft_strchr \
				 ft_strncmp \
				 ft_memcmp \
				 ft_tolower \
				 ft_toupper \
				 ft_atoi \
				 ft_calloc \
				 ft_strdup \
				 ft_strjoin \
				 ft_strtrim \
				 ft_itoa \
				 ft_strmapi \
				 ft_striteri \
				 ft_putchar_fd \
				 ft_putstr_fd \
				 ft_putendl_fd \
				 ft_putnbr_fd \
				 ft_split \
				 ft_substr \
				 )			

BONUS =	$(addsuffix .c, \
				 ft_lstnew \
				 ft_lstadd_front \
				 ft_lstsize \
				 ft_lstlast \
				 )

OBJS :=	$(SRC:%.c=%.o) #per each .c file will create a .o file

B_OBJ = $(BONUS:.c=.o)

CC=	gcc	#variable containing the compailer C Programs

CCFLAGS	=	-Wall -Werror -Wextra #compiler flags

INC_DIR	=	. # to include a header file

CPPFLAGS =-I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME) 

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	rm -f  $(OBJS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

bonus: $(NAME) $(B_OBJ)
	ar rcs $(NAME) $(B_OBJ)
	ranlib $(NAME)

.PHONY: all clean fclean re 
