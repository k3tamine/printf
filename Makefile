NAME = libftprintf.a

OPTION = -c

SRC = ft_printf.c fill_format.c tools.c

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	make fclean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all