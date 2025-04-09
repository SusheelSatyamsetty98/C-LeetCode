CXX = g++
CFLAGS = -Wall -Wextra -Werror -Wunused-variable

ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG_MODE
endif   

all: 
	$(CXX) -g $(CFLAGS) -o SpiralMatrix SpiralMatrix.cpp
clean:
	rm -rf SpiralMatrix