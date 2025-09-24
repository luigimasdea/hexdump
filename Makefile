# Nome del tuo programma eseguibile
TARGET = main
SRC = main.c
CC = gcc

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

run-clean: $(TARGET)
	./$(TARGET)
	rm -f $(TARGET)

clean:
	rm -f $(TARGET)
TARGET = main
