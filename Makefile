# Nome del tuo programma eseguibile
TARGET = main
SRC = main.c
CC = gcc

CFLAGS = -O3 -Wall -Wextra

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

run-clean: $(TARGET)
	./$(TARGET)
	rm -f $(TARGET)

clean:
	rm -f $(TARGET)
TARGET = main
