CC = gcc
FLAGS = -Wall -Wextra -O3
TARGET = card
RAN = randomizer
CODEPATH = ./code/
MAKEFLAGS += --silent
OUTPUT = ./output/output.txt
b:
	$(CC) $(FLAGS) -o $(TARGET) $(CODEPATH)$(TARGET).c
	$(CC) -Ofast -o $(RAN) $(CODEPATH)$(RAN).c
	@echo "Compiled successfully"
strip:
	strip $(TARGET) && strip $(RAN)
clean:
	rm -f output/output.txt
uninstall:
	rm -f $(TARGET)
	rm -f $(RAN)
c: clean uninstall
prepare: b strip
	@echo "Prepared for release"
generate: b
	@echo "Starting C.A.R.D"
	./$(RAN) | ./$(TARGET)
check:
	chmod +x sizecheck.sh
	./sizecheck.sh $(OUTPUT)