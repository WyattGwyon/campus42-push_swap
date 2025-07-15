# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clouden <clouden@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 18:43:41 by clouden           #+#    #+#              #
#    Updated: 2025/05/26 12:37:50 by clouden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
CFLAGS	+= -g3

# Name of the output static library
NAME    = libft.a

# Source and object files
SRCS    =	ft_atoi.c\
			ft_itoa.c\
			ft_putnbr_fd.c\
			ft_strlcpy.c\
			ft_tolower.c\
			ft_bzero.c\
			ft_memchr.c\
			ft_putstr_fd.c\
			ft_strlen.c\
			ft_toupper.c\
			ft_calloc.c\
			ft_memcmp.c\
			ft_split.c\
			ft_strmapi.c\
			ft_isalnum.c\
			ft_memcpy.c\
			ft_strchr.c\
			ft_strncmp.c\
			ft_isalpha.c\
			ft_memmove.c\
			ft_strdup.c\
			ft_strnstr.c\
			ft_isascii.c\
			ft_memset.c\
			ft_striteri.c\
			ft_strrchr.c\
			ft_isdigit.c\
			ft_putchar_fd.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_isprint.c\
			ft_putendl_fd.c\
			ft_strlcat.c\
			ft_substr.c
OBJS    = $(SRCS:.c=.o)

#Test file
TEST_SRC = .test.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_BIN = test_libft

# Default rule
all: $(NAME)

# Rule to build the library from object files
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile test
test: $(TEST_OBJ) $(NAME)
	$(CC) $(CFLAGS) $^ -o $(TEST_BIN) 

# Clean object files
clean:
	rm -f $(OBJS) $(TEST_OBJ)

# Clean object files and library
fclean: clean
	rm -f $(NAME) $(TEST_BIN)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re test
