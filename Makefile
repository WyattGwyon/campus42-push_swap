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
CFLAGS	=	-Wall -Wextra -Werror -I./include
#CFLAGS	+=	-g3

NAME	=	push_swap

SRC_DIR	=	src
OBJ_DIR	=	obj

SRCS	=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/parser/parse_input.c

OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT 	=	$(LIBFT_DIR)/libft.a

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re all clean fclean