CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunused-variable
LDFLAGS = -lpthread

ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG_MODE
endif   

all: 
	$(CC) -g $(CFLAGS) -o server socket_server.c $(LDFLAGS)
clean:
	rm -rf server
