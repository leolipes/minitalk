NAME = minitalk

SERVER = server
SRC_S = ./src/server.c

CLIENT = client
SRC_C = ./src/client.c

OBJ_S = ${SRC_S:.c=.o}
OBJ_C = ${SRC_C:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${SERVER} ${CLIENT}

$(SERVER): ${OBJ_S}
	make -C ./printf
	${CC} ${CFLAGS} -o ${SERVER} ${OBJ_S} -L./printf -lftprintf

$(CLIENT): ${OBJ_C}
	${CC} ${CFLAGS} -o ${CLIENT} ${OBJ_C} -L./printf -lftprintf

clean:
	make clean -C ./printf
	rm -f ${OBJ_C} ${OBJ_S}

fclean: clean
	make fclean -C ./printf
	rm -f ${CLIENT} ${SERVER}

re: fclean all
	make re -C ./printf

bonus: all