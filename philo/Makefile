# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 16:24:42 by swang             #+#    #+#              #
#    Updated: 2021/10/31 17:23:09 by swang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/

SRC_NAME = init.c\
			main.c\
			monitor_thread.c\
			philo_thread.c\
			philosopher.c\
			utils.c\
			print_mutex.c\

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm $(OBJS)

fclean : clean
		rm $(NAME)

re : fclean all

.PHONY : all clean fclean re