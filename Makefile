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
#CFLAGS	+=	-g3

NAME	=	push_swap

SRCS	=	main.c \
			parse_input.c

OBJS	=	$(SRCS:%.c=%.o)

LIBFT_DIR = libft
LIBFT 	=	$(LIBFT_DIR)/libft.a

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re all clean fclean