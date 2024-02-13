# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:53:11 by blackrider        #+#    #+#              #
#    Updated: 2024/01/25 15:29:27 by blackrider       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsortsalg.a
SRC = merge.c merge_sort.c merge_insert_sort.c insert_sort.c quick_sort.c
OBJDIR = objs
OBJECTS = $(SRC:%.c=$(OBJDIR)/%.o)
CC = gcc
CFLAGSO = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
