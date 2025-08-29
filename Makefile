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

RED		=	\033[0;31m
GREEN   =	\033[0;32m
RESET   =	\033[0m  
YELLOW  =	\033[1;33m
BLUE    =	\033[0;34m

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I./include -I./libft
#CFLAGS	+=	-g3 -Wno-unused-function

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
			errors.c\
			small_algos.c

OBJS	=	$(SRCS:%.c=%.o)

LIBFT_DIR = libft
LIBFT 	=	$(LIBFT_DIR)/libft.a

# TEST_SRC = .test.c
# TEST_OBJ = $(TEST_SRC:.c=.o)
# TEST_BIN = test

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	@echo "$(BLUE)[PUSH_SWAP]$(RESET) $< → $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all --no-print-directory

%.o: %.c
	@printf "$(BLUE)[COMPILING]$(RESET) %-21s → %s\n" $< $@
	@$(CC) $(CFLAGS) -c $< -o $@

# test: $(TEST_OBJ) $(NAME)
# 	$(CC) $(CFLAGS) $^ -o $(TEST_BIN)

clean:
	@echo "$(YELLOW)"
	@echo "+---------------------------+"
	@echo "|  🧹  CLEANING OBJECTS     |"
	@echo "+---------------------------+"
	
	@rm -rf *.o 
# $(TEST_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@echo "$(RED)"
	@echo "+---------------------------+"
	@echo "|  🔥 REMOVING EXECUTABLES  |"
	@echo "+---------------------------+"
	@rm -f $(NAME) 
# $(TEST_BIN)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(RESET)"
	@echo "...now THAT'S effin' clean!\n"

re: fclean all

.PHONY: re all clean fclean 
#test