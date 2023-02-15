##
## EPITECH PROJECT, 2022
## B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
## File description:
## Makefile for the B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle project
##

CLIENT_NAME	=	clientJ2T3

SERVER_NAME	= serverJ2T3

CLIENT_SRC	=	client/main.c				\
                client/background.c         \
                client/character.c          \
                client/gameloop.c           \
                client/gamemanager.c        \
                client/move.c               \
                client/obstacle.c			\
                client/coin.c

SERVER_SRC	=	server/main.c				\
				server/server_init.c		\
				server/player.c				\
				server/start_play.c			\
				server/map.c				\
				server/client.c				\
				server/server.c				\

CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)

CC	= gcc

DFLAGS	=	-I /opt/homebrew/Cellar/csfml/2.5.1/include -I./include

CFLAGS	=	-Wall -Wextra -I./client/inc -I./server/inc -Wpedantic -g3 -lm

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):	$(CLIENT_OBJ)
				$(CC) $(CLIENT_OBJ) $(DFLAGS) -o $(CLIENT_NAME) -g -L/opt/homebrew/Cellar/csfml/2.5.1/lib -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

$(SERVER_NAME): $(SERVER_OBJ)
				$(CC)	-o	$(SERVER_NAME)	$(SERVER_OBJ)

clean:
		rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)

fclean:	clean
		rm -rf $(CLIENT_NAME) $(SERVER_NAME)

re:	fclean all