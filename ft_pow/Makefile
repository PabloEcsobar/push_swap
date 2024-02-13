NAME = libftpow.a
NAME_TEST = ft_pow
TESTFILE = app
SRC = ft_pow.c tools.c approximation.c
SRCTEST = app.c
OBJDIR = objs
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
# OBJTEST = $(SRCTEST:%.c=$(OBJDIR)/%.o)
CC = gcc
CFLAGSO = -Wall -Wextra -Werror -c
LFLAGS = -L. -lftpow

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

$(NAME_TEST): all
	$(CC) -o $@ app.c $(LFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(NAME_TEST)

re: fclean all

run: $(NAME_TEST)
	./$(NAME_TEST)
