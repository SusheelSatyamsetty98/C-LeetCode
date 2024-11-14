CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunused-variable

ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG_MODE
endif   

all: 
	$(CC) -g $(CFLAGS) -o Swap2NodeInLinkedList Swap2NodeInLinkedList.c
clean:
	rm -rf Swap2NodeInLinkedList
