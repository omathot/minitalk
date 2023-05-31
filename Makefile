# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 12:45:54 by oscarmathot       #+#    #+#              #
#    Updated: 2023/05/31 12:37:47 by oscarmathot      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
SRC = server.c

CLIENT = client
SRC2 = client.c

OBJ = ${SRC:.c=.o}
OBJ2 = ${SRC2:.c=.o}

FLAGS = -Wall -Werror -Wextra

CC = gcc

.c.o: ${CC} ${FLAGS} -I minitalk.h -c $< -o ${<:.c=.o}

all: ${OBJ} ${OBJ2}
		$(MAKE) -C ./lib/printf all
		$(MAKE) -C ./lib/libft all
		$(CC) $(FLAGS) $(SRC) -o $(SERVER) lib/printf/libftprintf.a lib/libft/libft.a
		$(CC) $(FLAGS) $(SRC2) -o $(CLIENT) lib/printf/libftprintf.a lib/libft/libft.a

server: $(OBJ)
			$(MAKE) -C ./ftprintf all
			$(CC) $(FLAGS) $(SRC) -o $(SERVER) lib/printf/libftprintf.a lib/libft/libft.a

client:	$(OBJ2)
			$(MAKE) -C ./ftprintf all
			$(CC) $(FLAGS) $(SRC2) -o $(CLIENT) lib/printf/libftprintf.a lib/libft/libft.a

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ2)
	rm -rf $(OBJSERVERBONUS)
	rm -rf $(OBJCLIENTBONUS)

fclean : clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	rm -rf $(SERVERBONUS)
	rm -rf $(CLIENTBONUS)

hardclean : fclean
	$(MAKE) -C ./lib/printf fclean
	
re : fclean all

.PHONY: all clean fclean re bonus 