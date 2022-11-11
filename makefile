CC = g++
CFLAGS = -g -Wall -Wshadow -std=c++0x
LOCFLAGS = -lm -lpthread
SRC = $(wildcard *.cpp)
TAR = $(SRC:.cpp=.o)
EXEC = $(SRC:.cpp=)

MASTER_SRC = main.cpp
TARGET = P2
MASTER_OBJ = $(MASTER_SRC:.cpp=.o)
SHARE_OBJ = parser.o tree.o:

.PHONY: all clean

all: $(TAR)

%.o: %.cpp
	$(CC) $(CFLAGS) $(LOCFLAGS) -c $<
	$(CC) -o $* $@ $(CFLAGS) $(LOCFLAGS)

$(TARGET): $(MASTER_OBJ) $(SHARE_OBJ)
	$(CC) $(CFLAGS) $(MASTER_OBJ) $(OBJ)

clean:
	rm -f $(TAR)
	rm -f $(EXEC)
