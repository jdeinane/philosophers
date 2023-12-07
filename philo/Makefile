# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 13:03:47 by jubaldo           #+#    #+#              #
#    Updated: 2023/12/07 11:43:40 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	checking.c eat.c init_data.c main.c routine.c sleep.c \
				think.c time.c utils.c
	
CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
			@echo "\033[32m ~~ ./philo successfully created! ~~"
			@echo "$$BIBOU"

clean:
			$(RM)
			rm -rf $(OBJS)
			@echo "\033[31m ~~ ./philo successfully deleted! ~~"
			@echo "$$PQ"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[31m ~~ ./philo successfully fdeleted! ~~"

re:			fclean all

.PHONY:		all clean fclean re

info: bibou
define BIBOU
       _     _ _       
 _ __ | |__ (_) | ___  
| '_ \| '_ \| | |/ _ \ 
| |_) | | | | | | (_) |
| .__/|_| |_|_|_|\___/ 
|_|                   

endef
export BIBOU

info: pq
define PQ

 .--""--.___.._
(  <__>  )     `-.
|`--..--'|      <|      cleaning  ....
|       :|       /
|       :|--""-./
`.__  __;' 
    ""
endef
export PQ