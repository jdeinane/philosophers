# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:45:17 by jubaldo           #+#    #+#              #
#    Updated: 2023/11/16 10:49:05 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C
			$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
			@echo "\033[32m ~~ ./philo successfully created! ~~"
			@echo "$$BIBOU"

clean:
			make clean -C
			rm -rf $(OBJS)
			@echo "\033[31m ~~ ./philo successfully deleted! ~~"
			@echo "$$PQ"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[31m ~~ ./philo successfully fdeleted! ~~"
			@echo "$$PQ"

re:			fclean all

.PHONY:		all clean fclean re

|#----------------------random------------------------#
info: bibou
define BIBOU

.-------. .---.  .---..-./`)   .---.       ,-----.
\  _(`)_ \|   |  |_ _|\ .-.')  | ,_|     .'  .-,  '.
| (_ o._)||   |  ( ' )/ `-' \,-./  )    / ,-.|  \ _ \
|  (_,_) /|   '-(_{;}_)`-'`"`\  '_ '`) ;  \  '_ /  | :
|   '-.-' |      (_,_) .---.  > (_)  ) |  _`,/ \ _/  |
|   |     | _ _--.   | |   | (  .  .-' : (  '\_/ \   ;
|   |     |( ' ) |   | |   |  `-'`-'|___\ `"/  \  ) /
/   )     (_{;}_)|   | |   |   |        \'. \_/``".'
`---'     '(_,_) '---' '---'   `--------`  '-----'

endef
export BIBOU

info: pq
define PQ

 .--""--.___.._
(  <__>  )     `-.
|`--..--'|      <|
|       :|       /
|       :|--""-./
`.__  __;' 
    ""
endef
export PQ