CC = gcc
CFLAGS = -Wall -Wextra
TARGET = main.exe

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET) run

$(TARGET): $(OBJECTS)
	@echo +$@
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@

run: $(TARGET)
	@./$(TARGET)

%.o: %.c
	@echo +$@...
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -${OBJECTS}
	@echo -${TARGET}
	@if exist $(TARGET) del $(TARGET)
	@if exist $(OBJECTS) del $(OBJECTS)
	@echo OK