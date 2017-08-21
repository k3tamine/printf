# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 05:43:21 by mgonon            #+#    #+#              #
#    Updated: 2017/08/21 20:51:00 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Mais si tu veux des conseilles pour mon affichage super classe tu as des escape char: `\033[nA` pour remonter de `n` ligne (ou `\033[A` pour une seule ligne) et `\033[K` pour effacer la ligne a partir du curseur

NAME = libftprintf.a

OPTION = -c

SRCS = 	ft_printf.c \
		fill_format.c \
		tools.c \
		get_arg.c \
		get_char_arg.c \
		fill_unsigned.c \
		fill_signed.c \
		fill_characters.c \
		get_unicode.c

OBJS = $(addprefix srcs/, $(SRCS:.c=.o))

FLAGS = -Werror -Wall -Wextra

# all: compile
all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
# compile:
# 	make -C libft/
# 	$(MAKE) $(NAME)

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all