# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 12:43:58 by polenyc           #+#    #+#              #
#    Updated: 2024/02/14 14:14:01 by polenyc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEEXECUTE = push_swap
NAMECHECKER = checker
NAME = libpush_swap.a

TEST = test
TMP = libtmp.a
LIBS = libs
EXECPS_APP = pushswap.c
EXECCK_APP = checker.c

FILES = arr_sort.c dlist.c element_sort.c push_swap.c push.c rotate.c rrotate.c \
	swap.c sandytimes.c scatter.c trivial_sort.c stacktools_l.c stacktools_ll.c \
	tools.c score.c t_llist.c\
	
TESTFILE = test_onedata.c

TESTDIR = tests
SRCDIR = src
OBJDIR = $(SRCDIR)/objs
EXECDIR = executable

# SRC = $(addprefix $(SRCDIR)/, $(FILES))
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)/%.o)

TST = $(addprefix $(TESTDIR)/, $(TESTFILE))

FTPOWDIR = ft_pow
FTPRINTFDIR = ft_printf
GNLDIR = get_next_line
SORTADIR = sorts_alg

FTPOW = ftpow
FTPRINTF = ftprintf
GNL = gnl
SORTA = sortsalg

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGSO = -c -Wall -Wextra -Werror
LFTPRINTF = -L$(FTPRINTFDIR) -l$(FTPRINTF)
LFTPOW = -L$(FTPOWDIR) -l$(FTPOW)
LGNL = -L$(GNLDIR) -l$(GNL)
LSORTA = -L$(SORTADIR) -l$(SORTA)

.PHONY: all clean fclean re re_bonus checker

all: $(NAMEEXECUTE)

tst: $(TEST)

bonus: $(NAMEEXECUTE) $(NAMECHECKER)

$(NAMEEXECUTE): $(NAME)
	$(CC) $(CFLAGS) $(EXECDIR)/$(EXECPS_APP) $(NAME) -o $@

$(NAMECHECKER): $(NAME)
	$(CC) $(CFLAGS) $(EXECDIR)/$(EXECCK_APP) $(NAME) -o $@
  
$(NAME): $(OBJ) $(TMP)
	ar -rc $(NAME) *.o $(OBJ)
	ranlib $(NAME)
	rm -f *.o __.SYMDEF\ SORTED

$(TMP): $(FTPOW) $(FTPRINTF) $(GNL) $(SORTA)
	ar -x $(FTPRINTFDIR)/lib$(FTPRINTF).a
	ar -x $(FTPOWDIR)/lib$(FTPOW).a
	ar -x $(GNLDIR)/lib$(GNL).a
	ar -x $(SORTADIR)/lib$(SORTA).a
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

$(FTPOW):
	$(MAKE) -C $(FTPOWDIR)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTFDIR) bonus

$(GNL):
	$(MAKE) -C $(GNLDIR) bonus

$(SORTA):
	$(MAKE) -C $(SORTADIR)

$(TEST): $(NAME)
	$(CC) $(TST) $(NAME) -o $@

clean:
	$(MAKE) -C $(FTPOWDIR) clean
	$(MAKE) -C $(FTPRINTFDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(SORTADIR) clean
	rm -f *.o __.SYMDEF\ SORTED
	rm -rf $(OBJDIR) $(LIBS)

fclean: clean
	$(MAKE) -C $(FTPOWDIR) fclean
	$(MAKE) -C $(FTPRINTFDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(SORTADIR) fclean
	rm -f $(NAME) $(TEST) $(NAMEEXECUTE) $(NAMECHECKER)

re: fclean all

run: $(TEST)
	./$(TEST)

	