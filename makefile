CC = g++
CFLAGS = -g -Wall -Wshadow -std=c++0x
LOCFLAGS = -lm -lpthread
SRC = $(wildcard *.cpp)
TAR = $(SRC:.cpp=.o)
EXEC = $(SRC:.cpp=)

.PHONY: all clean

all: $(TAR)

%.o: %.c
	$(CC) $(CFLAGS) $(LOCFLAGS) -c $<
	$(CC) -o $* $@ $(CFLAGS) $(LOCFLAGS)

clean:
	rm -f $(TAR)
	rm -f $(EXEC)
