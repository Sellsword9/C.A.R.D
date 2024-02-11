FLAGS = -Ofast
TARGET = card
RAN = randomizer
CODEPATH = ./code/
MAKEFLAGS += --silent
OUTPUT = ./output/output.txt
b:
	gcc $(FLAGS) -o $(TARGET) $(CODEPATH)$(TARGET).c
	gcc -Ofast -o $(RAN) $(CODEPATH)$(RAN).c
	@echo "Compiled successfully"
strip:
	strip $(TARGET) && strip $(RAN)
clean:
	rm -f output/output.txt
c: clean
	rm -f $(TARGET)
	rm -f $(RAN)
generate: b strip
	./$(RAN) | ./$(TARGET)
check:
	chmod +x sizecheck.sh
	./sizecheck.sh $(OUTPUT)