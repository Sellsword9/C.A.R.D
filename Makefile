CC = gcc
FLAGS = -Wall -Wextra -O3
TARGET = card
dev:
	$(CC) $(FLAGS) -o $(TARGET) $(TARGET).c
strip:
	strip $(TARGET)
clean:
	rm -f $(TARGET)
	rm -f output/output.txt
run: 
	./$(TARGET)

b: dev
r: dev run
prepare: dev strip
c: clean
