# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 19:24:59 by clouden           #+#    #+#              #
#    Updated: 2025/07/16 19:25:04 by clouden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I./include -I./libft
CFLAGS	+=	-g3 -Wno-unused-function

NAME	=	push_swap

SRCS	=	main.c \
			parse_input.c\
			check_order.c\
			double_linked_lists.c\
			radix.c\
			stack.c\
			push.c\
			swap.c\
			rotate.c\
			rev_rotate.c\
			errors.c

OBJS	=	$(SRCS:%.c=%.o)

LIBFT_DIR = libft
LIBFT 	=	$(LIBFT_DIR)/libft.a

# TEST_SRC = .test.c
# TEST_OBJ = $(TEST_SRC:.c=.o)
# TEST_BIN = test

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# test: $(TEST_OBJ) $(NAME)
# 	$(CC) $(CFLAGS) $^ -o $(TEST_BIN)

clean:
	rm -rf *.o 
# $(TEST_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) 
# $(TEST_BIN)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re all clean fclean 
#test