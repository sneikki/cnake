#include "queue.h"

void init_graphics(void);
void draw(void);

void draw_arena(int width, int height);
void draw_apple(int x, int y);
void draw_snake(queue *snake);
void draw_text(char *text);

void close(void);
