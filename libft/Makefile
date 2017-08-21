# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 23:59:50 by mgonon            #+#    #+#              #
#    Updated: 2017/08/18 15:12:40 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	  ft_putchar.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_strcpy.c \
	  ft_strlen.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcmp.c \
	  ft_isalnum.c \
	  ft_isdigit.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_isalnum.c \
	  ft_atoi.c \
	  ft_strstr.c \
	  ft_strncmp.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strnstr.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strdel.c \
	  ft_strnew.c \
	  ft_memdel.c \
	  ft_memalloc.c \
	  ft_memset.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strupper.c \
	  ft_strjoin.c \
	  ft_strnjoin.c \
	  ft_strtrim.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strdup.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_memcmp.c \
	  ft_memchr.c \
	  ft_memmove.c \
	  ft_itoa.c \
	  ft_strlcat.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_strnew_c.c \
	  ft_itoa_base.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c -Werror -Wall -Wextra $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
