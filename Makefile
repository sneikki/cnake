src = main.c queue.c graphics.c game.c apple.c snake.c
flags = -lncursesw
output = lib/snake

.PHONY: directories

build: $(src) directories
	gcc $(src) $(flags) -o $(output)

run: $(output)
	$(output)

all: build run

directories:
	mkdir -p lib/
