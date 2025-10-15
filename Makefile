TARGET = main
SRC = main.c
CC = gcc

CFLAGS = -O3 -W -Wall -Wextra

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)
