# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:27:33 by mafranco          #+#    #+#              #
#    Updated: 2023/11/09 14:25:12 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CFLAGS	=	-Wall -Werror -Wextra
CC	=	gcc
RM	=	rm -f

LIB	=	inc/philo.h

SRC_FILES	=	src/initialize.c src/main.c src/utils.c \
			src/makepthread.c src/ft_threads.c

SRC_DIR	=	src

OBJ_DIR	=	.obj

#OBJ	=	$(SRC_DIR)/$(SRC_FILES:.c=.o)
OBJ_FILES	=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -lpthread $(CFLAGS) -o $@

clean:
	@$(RM) $(OBJ_DIR)/*.o

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
