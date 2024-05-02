# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 09:24:06 by bthomas           #+#    #+#              #
#    Updated: 2024/05/02 16:24:29 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a

CFILES		= get_next_line.c \
			  get_next_line_utils.c

OBJ_DIR		= objs
SRC_DIR		= src
OBJ 		= $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))
SRC			= $(addprefix $(SRC_DIR)/,$(CFILES))

CFLAGS		= -Wall -Werror -Wextra -g3 -Iincludes
COMPILER	= gcc
AR			= ar rcs

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
