# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smessal <smessal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:49:49 by smessal           #+#    #+#              #
#    Updated: 2022/12/27 03:55:48 by smessal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	$(wildcard srcs/*.c) \

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g -I./includes

NAME = philo
all	:	$(NAME)
$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o  $(NAME) -pthread
			
clean:
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re