# Project: Name
# Website http://herenkeskin.com
# Makefile created by Hasan Eren Keskin

CC 		:= g++
CFLAGS 	:= -Wall -g
TARGET 	:= proj

SRCS 	:= $(wildcard *.cpp)
OBJS 	:= $(patsubst %.cpp, %.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(TARGET) *.o *.txt

debug: clean all
	
.PHONY: debug clean all