# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 05:43:21 by mgonon            #+#    #+#              #
#    Updated: 2017/08/16 17:40:08 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all