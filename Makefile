# Nome del tuo programma eseguibile
TARGET = main

# File sorgenti C
SRCS = main.c

# Compilatore
CC = gcc

.PHONY: all clean run

# all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
