# NAME = ft_printf

NAME = libftprintf.a

OPTION = -c

SRC = ft_printf.c ft_itoa_base_buf.c feed_frmt.c check_is.c handle_d.c

# OBJ = ft_printf.o ft_itoa_base_buf.o feed_frmt.o check_is.o handle_d.o

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra

$(NAME):
	make -C libft/
	cp libft/libft.a ./$(NAME)
	gcc $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

# $(NAME):
# 	#make -C libft
# 	#gcc -c $(FLAGS) $(SRC)
# 	#gcc $(FLAGS) -o $(NAME) $(OBJ) libft.a
# 	gcc -o $(NAME) $(SRC) libft.a

# clean:
# 	rm -f $(OBJ)

# fclean:	clean
# 	#rm -f $(NAME) libft.a
# 	rm -f $(NAME)

clean:
	make fclean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all