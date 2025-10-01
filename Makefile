# Nome del tuo programma eseguibile
TARGET = main
SRC = main.c
CC = gcc

CFLAGS = -O3 -Wall -Wextra

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)
