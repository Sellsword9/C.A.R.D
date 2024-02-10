CC = gcc
FLAGS = -Wall -Wextra -O3
TARGET = card
RAN = randomizer
CODEPATH = ./code/
MAKEFLAGS += --silent
dev:
	$(CC) $(FLAGS) -o $(TARGET) $(CODEPATH)$(TARGET).c
	$(CC) -Ofast -o $(RAN) $(CODEPATH)$(RAN).c
	@echo "Compiled successfully"
strip:
	strip $(TARGET)
	strip $(RAN)
clean:
	rm -f $(TARGET)
	rm -f $(RAN)
	rm -f output/output.txt
run: 
	./$(TARGET)

b: dev
r: dev run
prepare: dev strip
c: clean
generate: dev 
	./$(RAN) | ./$(TARGET)