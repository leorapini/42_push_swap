# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 18:46:33 by lpinheir          #+#    #+#              #
#    Updated: 2022/03/24 14:22:56 by lpinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = -I includes -I $(LIBFT_DIR)/includes/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra 

RM_FLAGS = -f

S_DIR = srcs
O_DIR = objs

SRCS = $(S_DIR)/main.c \
		$(S_DIR)/utils.c \
		$(S_DIR)/str_utils.c \
		$(S_DIR)/swaps.c \

OBJS = $(subst $(S_DIR), $(O_DIR), $(SRCS:.c=.o))

$(O_DIR)/%.o:	$(S_DIR)/%.c
	$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

clean:
	make clean -C $(LIBFT_DIR)
	rm $(RM_FLAGS) $(OBJS)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm $(NAME)

re: fclean all