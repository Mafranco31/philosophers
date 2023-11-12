# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:27:33 by mafranco          #+#    #+#              #
#    Updated: 2023/11/13 00:30:16 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CFLAGS	=	-Wall -Werror -Wextra
CC	=	gcc
RM	=	rm -f

LIB	=	philo.h

SRC	=	initialize.c main.c utils.c makepthread.c ft_threads.c

#SRC_DIR	=	src

#OBJ_DIR	=	.obj

OBJ	=	$(SRC:.c=.o)
#OBJ_FILES	=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB)
#	@$(CC) $(CFLAGS) -c $< -o $@

%.o: $.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -lpthread $(CFLAGS) -o $@

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
