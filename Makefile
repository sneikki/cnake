src = main.c queue.c graphics.c game.c apple.c snake.c
flags = -lncursesw
output = lib/snake

.PHONY: directories

all: build run

build: $(src) directories
	gcc $(src) $(flags) -o $(output)

run: $(output)
	$(output)

directories:
	mkdir -p lib/
