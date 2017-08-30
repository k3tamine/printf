# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 05:43:21 by mgonon            #+#    #+#              #
#    Updated: 2017/08/24 17:39:41 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

OPTION 	= 	-c

S_DIR	=	srcs
O_DIR	=	objs
I_DIR	=	includes

INCS	=	ft_printf.h
FILES 	= 	ft_printf.c \
			fill_format.c \
			tools.c \
			get_arg.c \
			get_char_arg.c \
			fill_unsigned.c \
			fill_signed.c \
			fill_characters.c \
			get_unicode.c
SRCS	=	$(addprefix $(S_DIR)/, $(FILES))
OBJS 	=	$(SRCS:%.c=%.o)

FLAGS 	= 	-Werror -Wall -Wextra

all: $(NAME)

%.o: %.c $(I_DIR)/$(INCS)
	@echo "\033[1A\033[K\033[33;32mCompiling [$@]"
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo ""
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@echo "\033[33;32mCreating $(NAME)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[33;31mDeleting $(NAME)"

re: fclean all

.PHONY: re clean fclean all
