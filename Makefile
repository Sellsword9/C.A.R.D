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
uninstall:
	rm -f $(TARGET)
	rm -f $(RAN)
c: clean uninstall
generate: b strip
	@echo "Starting C.A.R.D"
	./$(RAN) | ./$(TARGET)
check:
	chmod +x sizecheck.sh
	./sizecheck.sh $(OUTPUT)