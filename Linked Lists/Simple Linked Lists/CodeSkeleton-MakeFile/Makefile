CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
