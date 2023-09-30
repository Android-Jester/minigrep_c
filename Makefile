CC=gcc

all: build test clean

build: main.c
	$(CC) -o minigrep main.c;

test: 
	./minigrep test.txt nobody
clean:
	rm minigrep