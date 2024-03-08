# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 13:45:41 by mafranco          #+#    #+#              #
#    Updated: 2024/03/08 20:42:46 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CFLAGS	=	-Wall -Werror -Wextra
CC	=	gcc
RM	=	rm -f

LIB	=	inc/philo.h

SRC	=	src/init_data.c src/main.c src/ft_atoi.c src/create_mutex.c \
		src/create_philo.c src/create_thread.c src/action.c \
		src/end_checker.c src/one_philo.c

OBJ	=	$(SRC:.c=.o)

%.o: $.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -lpthread $(CFLAGS) -o $@

clean:
	@$(RM) src/*.o

fclean:	clean
	@$(RM) $(NAME)

re:	fclean	all

.PHONY: all clean fclean re
