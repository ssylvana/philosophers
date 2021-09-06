# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssylvana <ssylvana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 01:53:51 by ssylvana          #+#    #+#              #
#    Updated: 2021/07/28 01:55:07 by ssylvana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo

SRCS 		= ft_death.c \
				ft_forks_time_write.c \
				ft_struct.c \
				pthread_create.c \

OBJS 		=	$(SRCS:.c=.o)

CC 			=	gcc

FLAGS		=	-g -Wall -Wextra -Werror -pthread

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all