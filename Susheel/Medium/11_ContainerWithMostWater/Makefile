CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunused-variable

ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG_MODE
endif   

all: 
	$(CC) -g $(CFLAGS) -o ContainerWithMostWater ContainerWithMostWater.c
clean:
	rm -rf ContainerWithMostWater
