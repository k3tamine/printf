NAME = libftprintf.a

OPTION = -c

SRC = ft_printf.c ft_itoa_base_buf.c ft_uitoa_base_buf.c feed_frmt.c check_is.c check_is2.c handle_di.c get_args.c handle_s.c

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	make -C libft/
	cp libft/libft.a ./$(NAME)
	gcc $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	make fclean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all