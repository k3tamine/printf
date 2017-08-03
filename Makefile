# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 05:43:21 by mgonon            #+#    #+#              #
#    Updated: 2017/08/02 13:26:13 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OPTION = -c

SRC = 	ft_printf.c \
		fill_format.c \
		tools.c \
		get_arg.c \
		get_char_arg.c \
		fill_unsigned.c \
		fill_signed.c \
		fill_characters.c \
		unicode.c

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all