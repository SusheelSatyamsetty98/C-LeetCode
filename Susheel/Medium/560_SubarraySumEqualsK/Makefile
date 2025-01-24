CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunused-variable

ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG_MODE
endif   

all: 
	$(CC) -g $(CFLAGS) -o SubarraySumEqualsK SubarraySumEqualsK.c
clean:
	rm -rf SubarraySumEqualsK
