# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behamon <behamon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 09:32:40 by behamon           #+#    #+#              #
#*   Updated: 2016/10/14 16:18:36 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_putendl.c \
	ft_atoi.c ft_itoa.c ft_strlen_n.c ft_swap.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
	ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_isspace.c ft_toupper.c ft_tolower.c \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strctrim.c ft_strsplit.c \
	ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
	ft_strlen_cmp.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c \
	get_next_line.c

OBJ = $(subst .c,.o,$(SRCS))

CFLAGS =  -Wall -Werror -Wextra

.PHONY: clean fclean all re

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Success : libft.a Created"

clean:
	@rm -f $(OBJ)
	@echo "Success : Objects Deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "Success : libft.a Deleted"

re: fclean all

